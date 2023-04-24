#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<vector>
#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

#define MAXTHREADS 32
#define N 100000

// 各个线程的浮点部分积
double partial_sum[MAXTHREADS];
// 各个线程元素的数量
unsigned long nelems_per_thread;
// 浮点向量定义
vector<double>vec1;
vector<double>vec2;

void *sum(void *arg);

int main(){
  pthread_t tid[MAXTHREADS];
  int myid[MAXTHREADS];
  int i, nthreads;
  double result = 0,duration=0;
  clock_t start,finish;

  vec1.resize(N);
  vec2.resize(N);
  // 浮点向量初始化
  for(int i=0;i<N;++i){
    if(i%3==0){
      vec1[i]=vec2[i]=1;
    }else if(i%3==1){
      vec1[i]=vec2[i]=-1;
    }else{
      vec1[i]=vec2[i]=0;
    }
  }
  // for(auto i:vec){
  //   cout<<i<<" ";
  // }

  cout<<"请输入线程数"<<endl;
  cin>>nthreads;
  nelems_per_thread = ceil(N/1.0/nthreads);

  start =clock();
  // 创建线程
  for(i=0;i<nthreads;++i){
    myid[i]=i;
    pthread_create(&tid[i],NULL,sum,&myid[i]);
  }
  // 线程等待
  for(i=0;i<nthreads;++i)
    pthread_join(tid[i],NULL);

  for(i=0;i<nthreads;++i)
    result += partial_sum[i];

  finish = clock();
  duration = (double)(finish-start)/CLOCKS_PER_SEC;
  cout<<"s="<<result<<endl;
  cout<<"t="<<duration*1000<<"ms"<<endl;
  exit(0);
}

void *sum(void *arg){
  int myid = *((int*)arg);
  unsigned long start = myid*nelems_per_thread;
  unsigned long end = start + nelems_per_thread;
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
