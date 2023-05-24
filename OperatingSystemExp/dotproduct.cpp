#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<vector>
#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

#define MAXTHREADS 32
#define N 100000000

// �����̵߳ĸ��㲿�ֻ�
double partial_sum[MAXTHREADS];
// �����߳�Ԫ�ص�����
long long nelems_per_thread;
// ������������
double* vec1 = (double*)malloc(sizeof(double)*N);
double* vec2 = (double*)malloc(sizeof(double)*N);

void *sum(void *arg);

int main(){
  pthread_t tid[MAXTHREADS];
  int myid[MAXTHREADS];
  int i,nthreads;
  double result = 0,duration=0;
  clock_t start,finish;

  // vec1.resize(N);
  // vec2.resize(N);
  // ����������ʼ��
  for(int i=0;i<N;++i){
    if(i%3==0){
      vec1[i]=vec2[i]=1;
    }else if(i%3==1){
      vec1[i]=vec2[i]=-1;
    }else{
      vec1[i]=vec2[i]=0;
    }
  }

  cout<<"�������߳���"<<endl;
  cin>>nthreads;
  nelems_per_thread = ceil(N/1.0/nthreads);

  start =clock();
  // �����߳�
  for(i=0;i<nthreads;++i){
    myid[i]=i;
    pthread_create(&tid[i],NULL,sum,&myid[i]);
  }
  // �̵߳ȴ�
  for(i=0;i<nthreads;++i)
    pthread_join(tid[i],NULL);

  for(i=0;i<nthreads;++i)
    result += partial_sum[i];

  finish = clock();
  duration = (double)(finish-start)/CLOCKS_PER_SEC;
  cout<<"s="<<result<<endl;
  cout<<"t="<<duration*1000<<"ms"<<endl;
  free(vec1);
  free(vec2);
  exit(0);
}

void *sum(void *arg){
  int myid = *((int*)arg);
  long long start = myid*nelems_per_thread;
  long long end = start + nelems_per_thread;
  if(end>N){
    end = N;
  }
  double temp_sum=0;
  int i;
  for(i=start;i<end;++i){
    temp_sum+=vec1[i]*vec2[i];
  }
  partial_sum[myid]=temp_sum;
  return NULL;
}
