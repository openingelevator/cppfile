#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdbool.h>

#define SHM_SIZE 64

typedef struct {
    int tid;  // �̺߳�
    int data; // �߳�����
    bool isEmpty; // �жϸû������Ƿ��������
} buffer_thread_data;

typedef struct 
{
   char letter; // �ַ�
   bool flag; // �жϸ��ַ��Ƿ�ʹ�ù�
} thread_letter;

buffer_thread_data buffer[SHM_SIZE];


sem_t mutex, sem_ac, sem_bd, empty;

void *producer_a(void *arg);
void *producer_b(void *arg);
void *consumer_c(void *arg);
void *consumer_d(void *arg);

int main()
{
    for(int i=0;i<SHM_SIZE;++i){
        buffer[i].isEmpty = true;
    }
    // ��ʼ���ź���
    sem_init(&mutex, 0, 1);
    sem_init(&sem_ac, 0, 0);
    sem_init(&sem_bd, 0, 0);
    sem_init(&empty, 0, SHM_SIZE);

    pthread_t p_a, p_b, c_c, c_d;

    // ���������ߺ��������߳�
    pthread_create(&p_a, NULL, producer_a, (void *)buffer);
    pthread_create(&p_b, NULL, producer_b, (void *)buffer);
    pthread_create(&c_c, NULL, consumer_c, (void *)buffer);
    pthread_create(&c_d, NULL, consumer_d, (void *)buffer);

    // �ȴ��߳̽���
    pthread_join(p_a, NULL);
    pthread_join(p_b, NULL);
    pthread_join(c_c, NULL);
    pthread_join(c_d, NULL);

    return 0;
}

void *producer_a(void *arg)
{
    buffer_thread_data *shared_buffer = (buffer_thread_data *)arg;
    int i;

    for (i = 0; i < 10000; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("a��������\n");
        for(int j =0 ;j<SHM_SIZE;++j){
            if(shared_buffer[j].isEmpty == true){
                shared_buffer[j].tid =1;
                shared_buffer[j].data = i;
                shared_buffer[j].isEmpty = false;
                break;
            }
        }
        printf("������a������Ʒ\n");
        sem_post(&mutex);
        sem_post(&sem_ac);
        printf("a���̽���\n");
    }
    return NULL;
}

void *producer_b(void *arg)
{
    buffer_thread_data *shared_buffer = (buffer_thread_data *)arg;
    thread_letter letters[26];
    for(int j=0;j<26;++j){
        letters[j].letter=(char)('a'+j);
        letters[j].flag = false;
    }
    int i;
    for (i = 0; i < 26; i++) {
        int idx;
        do{
            idx=rand()%26;
        }while(letters[idx].flag==true);
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("b��������\n");
        for(int j =0 ;j<SHM_SIZE;++j){
            if(shared_buffer[j].isEmpty == true){
                shared_buffer[j].tid =2;
                shared_buffer[j].data = letters[idx].letter;
                shared_buffer[j].isEmpty = false;
                break;
            }
        }
        printf("������b������Ʒ\n");
        sem_post(&mutex);
        sem_post(&sem_bd);
        printf("b���̽���\n");
    }
  return NULL;
}
void *consumer_c(void *arg)
{
buffer_thread_data *shared_buffer = (buffer_thread_data *)arg;
FILE *fp;
int i, num;
fp = fopen("a.out", "w");
if (fp == NULL) {
    perror("fopen");
    exit(1);
}

for (i = 0; i < 10000; i++) {
    sem_wait(&sem_ac);
    sem_wait(&mutex);
    printf("c��������\n");
        for(int j =0 ;j<SHM_SIZE;++j){
            if(shared_buffer[j].isEmpty == false&&
            shared_buffer[j].tid==1){
                num=shared_buffer[j].data;
                shared_buffer[j].isEmpty = true;
                break;
            }
        }
    printf("������c���Ѳ�Ʒ\n");
    sem_post(&mutex);
    sem_post(&empty);
    printf("c���̽���\n");
    fprintf(fp, "%d:%d\n", getpid(), num);
}
fclose(fp);
return NULL;
}

void *consumer_d(void *arg)
{
buffer_thread_data *shared_buffer = (buffer_thread_data *)arg;
FILE *fp;
int i;
char letter;
fp = fopen("b.out", "w");
if (fp == NULL) {
    perror("fopen");
    exit(1);
}

for (i = 0; i < 26; i++) {
    sem_wait(&sem_bd);
    sem_wait(&mutex);
    printf("d��������\n");
        for(int j =0 ;j<SHM_SIZE;++j){
            if(shared_buffer[j].isEmpty == false&&
            shared_buffer[j].tid==2){
                letter=(char)shared_buffer[j].data;
                shared_buffer[j].isEmpty = true;
                break;
            }
        }
    printf("������d���Ѳ�Ʒ\n");
    sem_post(&mutex);
    sem_post(&empty);
    printf("d���̽���\n");
    fprintf(fp, "%d:%c\n", getpid(),letter);
}

fclose(fp);
return NULL;
}

