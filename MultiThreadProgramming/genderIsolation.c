#include <stdio.h>
#include <pthread.h>

// ����ȫ�ֱ�������ʾԡ��״̬
int bathroom_state = 0;  // 0 ��ʾ�գ�1 ��ʾ��Ů����2 ��ʾ������

int num_women = 0;  // ��ǰ��ԡ�ҵ�Ů������
int num_men = 0;    // ��ǰ��ԡ�ҵ���������

// ���廥���������ڱ�֤ԡ��״̬����ȷ��
pthread_mutex_t bathroom_mutex = PTHREAD_MUTEX_INITIALIZER;

// ������������������ʵ���߳�ͬ��
pthread_cond_t woman_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t man_cond = PTHREAD_COND_INITIALIZER;

// ���庯������ʾŮ�������ԡ��
void* woman_wants_to_enter(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // ����

    while (bathroom_state == 2) {  // ��������ʱ��Ů���ȴ�
        pthread_cond_wait(&woman_cond, &bathroom_mutex);
    }

    bathroom_state = 1;  // ����ԡ�ң�����״̬Ϊ��Ů��
    num_women++;
    printf("Woman entered bathroom. There are %d women\n", num_women);

    pthread_mutex_unlock(&bathroom_mutex);  // ����
    return NULL;
}

// ���庯������ʾ���������ԡ��
void* man_wants_to_enter(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // ����

    while (bathroom_state == 1) {  // ����Ů��ʱ�������ȴ�
        pthread_cond_wait(&man_cond, &bathroom_mutex);
    }

    bathroom_state = 2;  // ����ԡ�ң�����״̬Ϊ������
    num_men++;
    printf("Man entered bathroom. There are %d men\n", num_men);

    pthread_mutex_unlock(&bathroom_mutex);  // ����
    return NULL;
}

// ���庯������ʾŮ���뿪ԡ��
void* woman_leaves(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // ����

    bathroom_state = 0;  // �뿪ԡ�ң�����״̬Ϊ��
    num_women--;
    printf("Woman left bathroom. There are %d women\n", num_women);

    pthread_cond_signal(&man_cond);  // ֪ͨ�������Խ���
    pthread_cond_signal(&woman_cond);  // ֪ͨŮ�����Խ���

    pthread_mutex_unlock(&bathroom_mutex);  // ����
    return NULL;
}

// ���庯������ʾ�����뿪ԡ��
void* man_leaves(void* arg) {
    pthread_mutex_lock(&bathroom_mutex);  // ����

    bathroom_state = 0;  // �뿪ԡ�ң�����״̬Ϊ��
    num_men--;
    printf("Man left bathroom. There are %d men\n", num_men);

    pthread_cond_signal(&man_cond);  // ֪ͨ�������Խ���
    pthread_cond_signal(&woman_cond);  // ֪ͨŮ�����Խ���

    pthread_mutex_unlock(&bathroom_mutex);  // ����
    return NULL;
}

// �����������ڲ���
int main() {
    // ��������̣߳���ʾ��ͬ�����
    pthread_t woman1, woman2, man1, man2;

    // �ֱ��ʾŮ��1��Ů��2������1������2�����ԡ��
    pthread_create(&woman1, NULL, woman_wants_to_enter, NULL);
    pthread_create(&woman2, NULL, woman_wants_to_enter, NULL);
    pthread_create(&man1, NULL,  man_wants_to_enter, NULL);
    pthread_create(&man2, NULL,  man_wants_to_enter, NULL);
    // �ֱ��ʾŮ��1������1������2�뿪ԡ��
    pthread_create(&woman1, NULL, woman_leaves, NULL);
    pthread_create(&woman2, NULL, woman_leaves, NULL);
    pthread_create(&man1, NULL, man_leaves, NULL);
    pthread_create(&man2, NULL, man_leaves, NULL);

    // �ȴ������߳�ִ�����
    pthread_join(woman1, NULL);
    pthread_join(woman2, NULL);
    pthread_join(man1, NULL);
    pthread_join(man2, NULL);

    return 0;
}  
