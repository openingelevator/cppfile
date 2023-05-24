#include<iostream>
using namespace std;

#define N 6
#define time_slices 3
enum State{
	READY,//就绪态
	BLOCK,//阻塞态
	FINSHED//完成态度
};

typedef struct {
    int pid;  // 进程号
    int arrive_time;  //到达时间
    int execute_time;  //执行时间
    int priority_rank;  //优先级
		enum State pro_state;  //进程状态
} process;

class CircleArray
{
public:
	CircleArray(int Size) :maxSize(Size), arr(new process[maxSize])
	{
		front = 0;
		rear = 0;
	}
	~CircleArray()
	{
		delete[] arr;
	}

	//判断队列是否为满
	bool isFull()
	{
		return (rear + 1) % maxSize == front;
	}
	//判断队列是否为空
	bool isEmpty()
	{
		return rear == front;
	}
	//添加数据到队列
	void addQueue(int pid, int arr_t, int exe_t, int prior=0,State sta=READY)
	{
		//判断队列是否满
		if (isFull())
		{
			cout << "队列满，不能加入数据" << endl;
			return;
		}
		//直接将数据加入
		arr[rear].pid = pid;
    arr[rear].arrive_time=arr_t;
    arr[rear].execute_time=exe_t;
    arr[rear].priority_rank=prior;
		arr[rear].pro_state=sta;
		//将rear指针后移
		rear = (rear + 1) % maxSize;
	}
	//获取队列的数据，出队列
	process getQueue()
	{
		if (isEmpty())
		{
			throw invalid_argument("队列为空，无法取得数据");
		}
		//先把front对应的值保存到临时变量
		process temp = arr[front];
		//将front后移
		front = (front + 1) % maxSize;
		return temp;
	}
	//显示队列的所有数据
	void showQueue()
	{
		if (isEmpty())
		{
			cout << "队列为空，没有数据" << endl;
		}
		//从front开始遍历(rear+maxSize-front)%maxSize个元素
		for (int i = front; i <front+validSize(); i++)
		{
			cout << "process["<<i%maxSize<<"]"<<"=" <<arr[i%maxSize].pid;
      if(i!=front+validSize()-1){
        cout<<"->";
      }
		}
    cout<<endl;
	}
	//显示队列的头数据
	process headQueue()
	{
		//判断队列是否为空
		if (isEmpty())
		{
			throw invalid_argument("队列为空，无法取得数据");
		}
		return arr[front];
	}

	//求出当前队列有效数据的元素
	int validSize()
	{
		return (rear + maxSize - front) % maxSize;
	}

  //将队首元素移动到队尾
  void moveRear(){
			// 复制队首元素到队尾
      arr[rear].pid=arr[front].pid;
      arr[rear].arrive_time=arr[front].arrive_time;
      arr[rear].execute_time=arr[front].execute_time;
      arr[rear].priority_rank=arr[front].priority_rank;
			arr[rear].pro_state=arr[front].pro_state;
			// 同时移动队首与队尾指针
      front = (front + 1) % maxSize;
      rear = (rear + 1) % maxSize;
  }
	//获取队首指针
	int getFront(){
		return front;
	}
	//获取队尾指针
	int getRear(){
		return rear;
	}
  //返回某个位置的进程
  process getProcess(int pos){
		pos=pos%maxSize;
    return arr[pos];
  }

  //修改进程数据
  void setExeTime(int time,int pos){
		pos=pos%maxSize;
    arr[pos].execute_time=time;
  }
	void setState(State sta,int pos){
		pos=pos%maxSize;
		arr[pos].pro_state=sta;
	}
private:
	//表示数组的最大容量
	int maxSize;
	//指向队列头位置的指针
	int front;
	//指向队列尾后一个位置的指针
	int rear;
	//用于存放数据的数组
	process* arr;
};

int main()
{
	cout<<"采用时间片轮询算法"<<endl;
  CircleArray ca(N);
  //创建进程就绪队列
  ca.addQueue(6601,0,7);
  ca.addQueue(6602,2,4);
  ca.addQueue(6603,4,1);
  ca.addQueue(6604,5,4);
	ca.addQueue(6605,7,5);
	cout<<"处理机调度前就绪队列中的进程有"<<endl;
	ca.showQueue();

  //执行时间记录
  int time=0,count=1;
  int front,logic_rear, cur;
  process cur_proc,next_proc;
  //采用时间片轮询算法
  while(!ca.isEmpty()){
    cout<<"第"<<count<<"轮进程调度"<<endl;
		// 获取队列中首个进程的位置，同时计算出逻辑上队尾指针的位置
    front = ca.getFront();
    logic_rear=ca.validSize()+front;
		// 将当前执行运行进程的指针指向队首进程
    cur=front;
    while(cur<logic_rear){
        cur_proc=ca.getProcess(cur);
				//为到达进程分配时间片
        cout<<"选中进程"<<cur_proc.pid<<"---该进程在时间点"<<time<<"开始执行---";
				int exe_time;
        next_proc=ca.getProcess(cur+1);
        //如果进程在时间片内能够执行完，则把进程推出就绪队列
        if(cur_proc.execute_time<=time_slices){
					//计算进程执行时间
          exe_time=cur_proc.execute_time;
          time+=exe_time;
					//将该进程剩余执行时间置零
					ca.setExeTime(0,cur);
					//设置该进程状态为完成态
					ca.setState(FINSHED,cur);
					//将进程移出队列
					ca.getQueue();
        }else{//进程在时间片内不能执行完，进程在时间片结束后移动到队尾 
          exe_time=time_slices;
					time+=exe_time;
					//设置该进程剩余完成时间
					cur_proc.execute_time-=exe_time;
          ca.setExeTime(cur_proc.execute_time,cur);
					//将该进程从队首移向队尾
          ca.moveRear();
        }
        if(time<next_proc.arrive_time){
            time=next_proc.arrive_time;
        }
				cout<<"共运行了"<<exe_time<<"个时间片"<<endl;
        cur++;
    }
    cout<<"第"<<count<<"轮调度后就绪队列中的进程有"<<endl;
    ca.showQueue();
		// cout<<endl;
    count++;
  }
  cout<<"总的执行时间为:"<<time<<endl;
	cout<<endl;

	cout<<"采用优先级调度算法"<<endl;
	CircleArray ca2(N);
  ca2.addQueue(6601,0,7,1);
  ca2.addQueue(6602,2,4,2);
  ca2.addQueue(6603,4,1,3);
  ca2.addQueue(6604,5,4,2);
	ca2.addQueue(6605,7,3,4);
  cout<<"处理机调度前就绪队列中的进程有"<<endl;
	ca2.showQueue();
  //采用优先级调度算法
	count=1;
	time=0;
	while (!ca2.isEmpty())
	{
		cout<<"第"<<count<<"轮进程调度"<<endl;
		//获取队列中首个进程的位置，同时计算出逻辑上队尾指针的位置
    front = ca2.getFront();
    logic_rear=ca2.validSize()+front;
		//将当前执行运行进程的指针指向队首进程
    cur=front;
		if(count==1){
		while(cur<logic_rear){
			  cur_proc=ca2.getProcess(cur);
        cout<<"选中进程"<<cur_proc.pid<<"---该进程在时间点"<<time<<"开始执行---";
				int exe_time;
        next_proc=ca2.getProcess(cur+1);
				//该进程未执行完，下一个优先级更高的进程到达，该进程被抢占
				if(time+cur_proc.execute_time>next_proc.arrive_time
				&&cur_proc.priority_rank<next_proc.priority_rank){
					exe_time=next_proc.arrive_time-time;
					time+=exe_time;
          cur_proc.execute_time-=exe_time;
					ca2.setExeTime(cur_proc.execute_time,cur);
          ca2.moveRear();
				}else{//该进程正常执行完，处理机空闲，等待下一个进程到达
					exe_time=cur_proc.execute_time;
					time=(time+exe_time>next_proc.arrive_time)?time+exe_time:next_proc.arrive_time;
					ca2.setExeTime(0,cur);
					ca2.setState(FINSHED,cur);
					ca2.getQueue();
				}
				cout<<"共运行了"<<exe_time<<"个时间片"<<endl;
        cur++;
		}
		}else{
			//第一轮执行完后，没有新的进程到达，则按顺序将队列中剩余的进程执行完
			int exe_time;
			for(int i=front;i<logic_rear;++i){
					cur_proc=ca2.getProcess(i);
          cout<<"选中进程"<<cur_proc.pid<<"---该进程在时间点"<<time<<"开始执行---";
				  exe_time=cur_proc.execute_time;
					time+=exe_time;
					ca2.setExeTime(0,cur);
					ca2.setState(FINSHED,cur);
					ca2.getQueue();
					cout<<"共运行了"<<exe_time<<"个时间片"<<endl;
			}
		}
			cout<<"第"<<count<<"轮调度后就绪队列中的进程有"<<endl;
    	ca2.showQueue();
    	count++;
	}
	cout<<"总的执行时间为:"<<time<<endl;
	cout<<endl;
	
  system("pause");
	return 0;
}