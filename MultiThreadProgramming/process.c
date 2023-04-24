#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include<sys/wait.h>
#include<string.h>


#define SHM_SIZE 64     // �����ڴ��С
#define BUFFER_SIZE 100 // ��������С

// ���干���ڴ�ṹ��
typedef struct {
    int pid;  // ���̺�
    union {
        int num;
        char letter;
    } data;  // ����
} shared_mem_t;

int main() {
    int i, fd_a, fd_b;
    pid_t pid_a, pid_b, pid_c, pid_d;
    shared_mem_t *shm_ptr;
    sem_t *sem_ptr, *sem_ac_ptr, *sem_bd_ptr,*sem_only;
    char buffer[BUFFER_SIZE];

    // ���������ڴ���ź���
    int shm_fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_ptr = sem_open("/mysem", O_CREAT | O_RDWR, 0666, 1);
    sem_ac_ptr = sem_open("/ac",O_CREAT | O_RDWR, 0666, 0);
    sem_bd_ptr = sem_open("/bd",O_CREAT | O_RDWR, 0666, 0);
    sem_only = sem_open("only",O_CREAT | O_RDWR, 0666, 1);

    // �����ļ����������
    fd_a = open("a.out", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    fd_b = open("b.out", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    // ���������߽���a
    pid_a = fork();
    if (pid_a == 0) {
        for (i = 0; i < 10000; i++) {
            sem_wait(sem_only);
            sem_wait(sem_ptr); // P����
            printf("a��������\n");
            shm_ptr->pid = getpid();
            shm_ptr->data.num = i;
            printf("������a������Ʒ\n");
            sem_post(sem_ptr); // V����
            sem_post(sem_ac_ptr);
            printf("a���̽���\n");
        }
        exit(0);
    }

    // ���������߽���b
    pid_b = fork();
    if (pid_b == 0) {
        char letters[] = "abcdefghijklmnopqrstuvwxyz";
        int index = 0;
        while (index < 26) {
            sem_wait(sem_only);
            sem_wait(sem_ptr); // P����
            printf("b��������\n");
            if (letters[index] != 0) {
                shm_ptr->pid = getpid();
                shm_ptr->data.letter = letters[index];
                letters[index] = 0;
                index++;
            }
            printf("������b������Ʒ\n");
            sem_post(sem_ptr); // V����
            sem_post(sem_bd_ptr);
            printf("b���̽���\n");
        }
        exit(0);
    }

    // ���������߽���c
    pid_c = fork();
    if (pid_c == 0) {
        for (i = 0; i < 10000; i++) {
            sem_wait(sem_ac_ptr);
            sem_wait(sem_ptr); // P����
            printf("c��������\n");
            if (shm_ptr->pid == pid_a) {
                sprintf(buffer, "%d %d\n", shm_ptr->pid, shm_ptr->data.num);
                write(fd_a, buffer, strlen(buffer));
            }
            printf("������c���Ѳ�Ʒ\n");
            sem_post(sem_ptr); // V����
            sem_post(sem_only);
            printf("c���̽���\n");
        }
        exit(0);
    }

    // ���������߽���d
    pid_d = fork();
    if (pid_d == 0) {
        for (i = 0; i < 26; i++) {
            sem_wait(sem_bd_ptr);
            sem_wait(sem_ptr); // P����
            printf("d��������\n");
            if (shm_ptr->pid == pid_b) {
                sprintf(buffer, "%d %c\n", shm_ptr->pid, shm_ptr->data.letter);
                write(fd_b, buffer, strlen(buffer));
            }
            printf("������d���Ѳ�Ʒ\n");
            sem_post(sem_ptr); // V����
            sem_post(sem_only);
            printf("d���̽���\n");
    }
    exit(0);
}

// �ȴ������ӽ��̽���
waitpid(pid_a, NULL, 0);
waitpid(pid_b, NULL, 0);
waitpid(pid_c, NULL, 0);
waitpid(pid_d, NULL, 0);

// �رպͽ��ӳ�乲���ڴ�
munmap(shm_ptr, SHM_SIZE);
close(shm_fd);
shm_unlink("/myshm");

// �ر��ļ����ź���
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