#include <stdio.h>
#include <pthread.h>

// 定义全局变量，表示浴室状态
int bathroom_state = 0;  // 0 表示空，1 表示有女生，2 表示有男生

int num_women = 0;  // 当前在浴室的女生数量
int num_men = 0;    // 当前在浴室的男生数量

// 定义互斥锁，用于保证浴室状态的正确性
pthread_mutex_t bathroom_mutex = PTHREAD_MUTEX_INITIALIZER;

// 定义条件变量，用于实现线程同步
pthread_cond_t woman_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t man_cond = PTHREAD_COND_INITIALIZER;

// 定义函数，表示女生想进入浴室
void* woman_wants_to_enter(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // 加锁

    while (bathroom_state == 2) {  // 当有男生时，女生等待
        pthread_cond_wait(&woman_cond, &bathroom_mutex);
    }

    bathroom_state = 1;  // 进入浴室，设置状态为有女生
    num_women++;
    printf("Woman entered bathroom. There are %d women\n", num_women);

    pthread_mutex_unlock(&bathroom_mutex);  // 解锁
    return NULL;
}

// 定义函数，表示男生想进入浴室
void* man_wants_to_enter(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // 加锁

    while (bathroom_state == 1) {  // 当有女生时，男生等待
        pthread_cond_wait(&man_cond, &bathroom_mutex);
    }

    bathroom_state = 2;  // 进入浴室，设置状态为有男生
    num_men++;
    printf("Man entered bathroom. There are %d men\n", num_men);

    pthread_mutex_unlock(&bathroom_mutex);  // 解锁
    return NULL;
}

// 定义函数，表示女生离开浴室
void* woman_leaves(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // 加锁

    bathroom_state = 0;  // 离开浴室，设置状态为空
    num_women--;
    printf("Woman left bathroom. There are %d women\n", num_women);

    pthread_cond_signal(&man_cond);  // 通知男生可以进入
    pthread_cond_signal(&woman_cond);  // 通知女生可以进入

    pthread_mutex_unlock(&bathroom_mutex);  // 解锁
    return NULL;
}

// 定义函数，表示男生离开浴室
void* man_leaves(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // 加锁

    bathroom_state = 0;  // 离开浴室，设置状态为空
    num_men--;
    printf("Man left bathroom. There are %d men\n", num_men);

    pthread_cond_signal(&man_cond);  // 通知男生可以进入
    pthread_cond_signal(&woman_cond);  // 通知女生可以进入

    pthread_mutex_unlock(&bathroom_mutex);  // 解锁
    return NULL;
}

// 主函数，用于测试
int main() {
    // 创建多个线程，表示不同的情况
    pthread_t woman1, woman2, man1, man2;

    // 分别表示女生1、女生2、男生1、男生2想进入浴室
    pthread_create(&woman1, NULL, woman_wants_to_enter, NULL);
    pthread_create(&woman2, NULL, woman_wants_to_enter, NULL);
    pthread_create(&man1, NULL,  man_wants_to_enter, NULL);
    pthread_create(&man2, NULL,  man_wants_to_enter, NULL);
    // 分别表示女生1、男生1、男生2离开浴室
    pthread_create(&woman1, NULL, woman_leaves, NULL);
    pthread_create(&woman2, NULL, woman_leaves, NULL);
    pthread_create(&man1, NULL, man_leaves, NULL);
    pthread_create(&man2, NULL, man_leaves, NULL);

    // 等待所有线程执行完毕
    pthread_join(woman1, NULL);
    pthread_join(woman2, NULL);
    pthread_join(man1, NULL);
    pthread_join(man2, NULL);

    return 0;
}  
