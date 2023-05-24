#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include<sys/wait.h>
#include<string.h>


#define SHM_SIZE 64     // 共享内存大小
#define BUFFER_SIZE 100 // 缓冲区大小

// 定义共享内存结构体
typedef struct {
    int pid;  // 进程号
    union {
        int num;
        char letter;
    } data;  // 数据
} shared_mem_t;

int main() {
    int i, fd_a, fd_b;
    pid_t pid_a, pid_b, pid_c, pid_d;
    shared_mem_t *shm_ptr;
    sem_t *sem_ptr, *sem_ac_ptr, *sem_bd_ptr,*sem_only;
    char buffer[BUFFER_SIZE];

    // 创建共享内存和信号量
    int shm_fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_ptr = sem_open("/mysem", O_CREAT | O_RDWR, 0666, 1);
    sem_ac_ptr = sem_open("/ac",O_CREAT | O_RDWR, 0666, 0);
    sem_bd_ptr = sem_open("/bd",O_CREAT | O_RDWR, 0666, 0);
    sem_only = sem_open("only",O_CREAT | O_RDWR, 0666, 1);

    // 创建文件并清空内容
    fd_a = open("a.out", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    fd_b = open("b.out", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    // 创建生产者进程a
    pid_a = fork();
    if (pid_a == 0) {
        for (i = 0; i < 10000; i++) {
            sem_wait(sem_only);
            sem_wait(sem_ptr); // P操作
            printf("a进程上锁\n");
            shm_ptr->pid = getpid();
            shm_ptr->data.num = i;
            printf("生产者a生产产品\n");
            sem_post(sem_ptr); // V操作
            sem_post(sem_ac_ptr);
            printf("a进程解锁\n");
        }
        exit(0);
    }

    // 创建生产者进程b
    pid_b = fork();
    if (pid_b == 0) {
        char letters[] = "abcdefghijklmnopqrstuvwxyz";
        int index = 0;
        while (index < 26) {
            sem_wait(sem_only);
            sem_wait(sem_ptr); // P操作
            printf("b进程上锁\n");
            if (letters[index] != 0) {
                shm_ptr->pid = getpid();
                shm_ptr->data.letter = letters[index];
                letters[index] = 0;
                index++;
            }
            printf("生产者b生产产品\n");
            sem_post(sem_ptr); // V操作
            sem_post(sem_bd_ptr);
            printf("b进程解锁\n");
        }
        exit(0);
    }

    // 创建消费者进程c
    pid_c = fork();
    if (pid_c == 0) {
        for (i = 0; i < 10000; i++) {
            sem_wait(sem_ac_ptr);
            sem_wait(sem_ptr); // P操作
            printf("c进程上锁\n");
            if (shm_ptr->pid == pid_a) {
                sprintf(buffer, "%d %d\n", shm_ptr->pid, shm_ptr->data.num);
                write(fd_a, buffer, strlen(buffer));
            }
            printf("消费者c消费产品\n");
            sem_post(sem_ptr); // V操作
            sem_post(sem_only);
            printf("c进程解锁\n");
        }
        exit(0);
    }

    // 创建消费者进程d
    pid_d = fork();
    if (pid_d == 0) {
        for (i = 0; i < 26; i++) {
            sem_wait(sem_bd_ptr);
            sem_wait(sem_ptr); // P操作
            printf("d进程上锁\n");
            if (shm_ptr->pid == pid_b) {
                sprintf(buffer, "%d %c\n", shm_ptr->pid, shm_ptr->data.letter);
                write(fd_b, buffer, strlen(buffer));
            }
            printf("消费者d消费产品\n");
            sem_post(sem_ptr); // V操作
            sem_post(sem_only);
            printf("d进程解锁\n");
    }
    exit(0);
}

// 等待所有子进程结束
waitpid(pid_a, NULL, 0);
waitpid(pid_b, NULL, 0);
waitpid(pid_c, NULL, 0);
waitpid(pid_d, NULL, 0);

// 关闭和解除映射共享内存
munmap(shm_ptr, SHM_SIZE);
close(shm_fd);
shm_unlink("/myshm");

// 关闭文件和信号量
close(fd_a);
close(fd_b);
sem_close(sem_ptr);
sem_close(sem_ac_ptr);
sem_close(sem_bd_ptr);
sem_close(sem_only);
sem_unlink("/mysem");
sem_unlink("/ac");
sem_unlink("/bd");
sem_unlink("only");

return 0;
}