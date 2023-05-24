#include<iostream>
using namespace std;

#define N 6
#define time_slices 3
enum State{
	READY,//����̬
	BLOCK,//����̬
	FINSHED//���̬��
};

typedef struct {
    int pid;  // ���̺�
    int arrive_time;  //����ʱ��
    int execute_time;  //ִ��ʱ��
    int priority_rank;  //���ȼ�
		enum State pro_state;  //����״̬
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

	//�ж϶����Ƿ�Ϊ��
	bool isFull()
	{
		return (rear + 1) % maxSize == front;
	}
	//�ж϶����Ƿ�Ϊ��
	bool isEmpty()
	{
		return rear == front;
	}
	//������ݵ�����
	void addQueue(int pid, int arr_t, int exe_t, int prior=0,State sta=READY)
	{
		//�ж϶����Ƿ���
		if (isFull())
		{
			cout << "�����������ܼ�������" << endl;
			return;
		}
		//ֱ�ӽ����ݼ���
		arr[rear].pid = pid;
    arr[rear].arrive_time=arr_t;
    arr[rear].execute_time=exe_t;
    arr[rear].priority_rank=prior;
		arr[rear].pro_state=sta;
		//��rearָ�����
		rear = (rear + 1) % maxSize;
	}
	//��ȡ���е����ݣ�������
	process getQueue()
	{
		if (isEmpty())
		{
			throw invalid_argument("����Ϊ�գ��޷�ȡ������");
		}
		//�Ȱ�front��Ӧ��ֵ���浽��ʱ����
		process temp = arr[front];
		//��front����
		front = (front + 1) % maxSize;
		return temp;
	}
	//��ʾ���е���������
	void showQueue()
	{
		if (isEmpty())
		{
			cout << "����Ϊ�գ�û������" << endl;
		}
		//��front��ʼ����(rear+maxSize-front)%maxSize��Ԫ��
		for (int i = front; i <front+validSize(); i++)
		{
			cout << "process["<<i%maxSize<<"]"<<"=" <<arr[i%maxSize].pid;
      if(i!=front+validSize()-1){
        cout<<"->";
      }
		}
    cout<<endl;
	}
	//��ʾ���е�ͷ����
	process headQueue()
	{
		//�ж϶����Ƿ�Ϊ��
		if (isEmpty())
		{
			throw invalid_argument("����Ϊ�գ��޷�ȡ������");
		}
		return arr[front];
	}

	//�����ǰ������Ч���ݵ�Ԫ��
	int validSize()
	{
		return (rear + maxSize - front) % maxSize;
	}

  //������Ԫ���ƶ�����β
  void moveRear(){
			// ���ƶ���Ԫ�ص���β
      arr[rear].pid=arr[front].pid;
      arr[rear].arrive_time=arr[front].arrive_time;
      arr[rear].execute_time=arr[front].execute_time;
      arr[rear].priority_rank=arr[front].priority_rank;
			arr[rear].pro_state=arr[front].pro_state;
			// ͬʱ�ƶ��������βָ��
      front = (front + 1) % maxSize;
      rear = (rear + 1) % maxSize;
  }
	//��ȡ����ָ��
	int getFront(){
		return front;
	}
	//��ȡ��βָ��
	int getRear(){
		return rear;
	}
  //����ĳ��λ�õĽ���
  process getProcess(int pos){
		pos=pos%maxSize;
    return arr[pos];
  }

  //�޸Ľ�������
  void setExeTime(int time,int pos){
		pos=pos%maxSize;
    arr[pos].execute_time=time;
  }
	void setState(State sta,int pos){
		pos=pos%maxSize;
		arr[pos].pro_state=sta;
	}
private:
	//��ʾ������������
	int maxSize;
	//ָ�����ͷλ�õ�ָ��
	int front;
	//ָ�����β��һ��λ�õ�ָ��
	int rear;
	//���ڴ�����ݵ�����
	process* arr;
};

int main()
{
	cout<<"����ʱ��Ƭ��ѯ�㷨"<<endl;
  CircleArray ca(N);
  //�������̾�������
  ca.addQueue(6601,0,7);
  ca.addQueue(6602,2,4);
  ca.addQueue(6603,4,1);
  ca.addQueue(6604,5,4);
	ca.addQueue(6605,7,5);
	cout<<"���������ǰ���������еĽ�����"<<endl;
	ca.showQueue();

  //ִ��ʱ���¼
  int time=0,count=1;
  int front,logic_rear, cur;
  process cur_proc,next_proc;
  //����ʱ��Ƭ��ѯ�㷨
  while(!ca.isEmpty()){
    cout<<"��"<<count<<"�ֽ��̵���"<<endl;
		// ��ȡ�������׸����̵�λ�ã�ͬʱ������߼��϶�βָ���λ��
    front = ca.getFront();
    logic_rear=ca.validSize()+front;
		// ����ǰִ�����н��̵�ָ��ָ����׽���
    cur=front;
    while(cur<logic_rear){
        cur_proc=ca.getProcess(cur);
				//Ϊ������̷���ʱ��Ƭ
        cout<<"ѡ�н���"<<cur_proc.pid<<"---�ý�����ʱ���"<<time<<"��ʼִ��---";
				int exe_time;
        next_proc=ca.getProcess(cur+1);
        //���������ʱ��Ƭ���ܹ�ִ���꣬��ѽ����Ƴ���������
        if(cur_proc.execute_time<=time_slices){
					//�������ִ��ʱ��
          exe_time=cur_proc.execute_time;
          time+=exe_time;
					//���ý���ʣ��ִ��ʱ������
					ca.setExeTime(0,cur);
					//���øý���״̬Ϊ���̬
					ca.setState(FINSHED,cur);
					//�������Ƴ�����
					ca.getQueue();
        }else{//������ʱ��Ƭ�ڲ���ִ���꣬������ʱ��Ƭ�������ƶ�����β 
          exe_time=time_slices;
					time+=exe_time;
					//���øý���ʣ�����ʱ��
					cur_proc.execute_time-=exe_time;
          ca.setExeTime(cur_proc.execute_time,cur);
					//���ý��̴Ӷ��������β
          ca.moveRear();
        }
        if(time<next_proc.arrive_time){
            time=next_proc.arrive_time;
        }
				cout<<"��������"<<exe_time<<"��ʱ��Ƭ"<<endl;
        cur++;
    }
    cout<<"��"<<count<<"�ֵ��Ⱥ���������еĽ�����"<<endl;
    ca.showQueue();
		// cout<<endl;
    count++;
  }
  cout<<"�ܵ�ִ��ʱ��Ϊ:"<<time<<endl;
	cout<<endl;

	cout<<"�������ȼ������㷨"<<endl;
	CircleArray ca2(N);
  ca2.addQueue(6601,0,7,1);
  ca2.addQueue(6602,2,4,2);
  ca2.addQueue(6603,4,1,3);
  ca2.addQueue(6604,5,4,2);
	ca2.addQueue(6605,7,3,4);
  cout<<"���������ǰ���������еĽ�����"<<endl;
	ca2.showQueue();
  //�������ȼ������㷨
	count=1;
	time=0;
	while (!ca2.isEmpty())
	{
		cout<<"��"<<count<<"�ֽ��̵���"<<endl;
		//��ȡ�������׸����̵�λ�ã�ͬʱ������߼��϶�βָ���λ��
    front = ca2.getFront();
    logic_rear=ca2.validSize()+front;
		//����ǰִ�����н��̵�ָ��ָ����׽���
    cur=front;
		if(count==1){
		while(cur<logic_rear){
			  cur_proc=ca2.getProcess(cur);
        cout<<"ѡ�н���"<<cur_proc.pid<<"---�ý�����ʱ���"<<time<<"��ʼִ��---";
				int exe_time;
        next_proc=ca2.getProcess(cur+1);
				//�ý���δִ���꣬��һ�����ȼ����ߵĽ��̵���ý��̱���ռ
				if(time+cur_proc.execute_time>next_proc.arrive_time
				&&cur_proc.priority_rank<next_proc.priority_rank){
					exe_time=next_proc.arrive_time-time;
					time+=exe_time;
          cur_proc.execute_time-=exe_time;
					ca2.setExeTime(cur_proc.execute_time,cur);
          ca2.moveRear();
				}else{//�ý�������ִ���꣬��������У��ȴ���һ�����̵���
					exe_time=cur_proc.execute_time;
					time=(time+exe_time>next_proc.arrive_time)?time+exe_time:next_proc.arrive_time;
					ca2.setExeTime(0,cur);
					ca2.setState(FINSHED,cur);
					ca2.getQueue();
				}
				cout<<"��������"<<exe_time<<"��ʱ��Ƭ"<<endl;
        cur++;
		}
		}else{
			//��һ��ִ�����û���µĽ��̵����˳�򽫶�����ʣ��Ľ���ִ����
			int exe_time;
			for(int i=front;i<logic_rear;++i){
					cur_proc=ca2.getProcess(i);
          cout<<"ѡ�н���"<<cur_proc.pid<<"---�ý�����ʱ���"<<time<<"��ʼִ��---";
				  exe_time=cur_proc.execute_time;
					time+=exe_time;
					ca2.setExeTime(0,cur);
					ca2.setState(FINSHED,cur);
					ca2.getQueue();
					cout<<"��������"<<exe_time<<"��ʱ��Ƭ"<<endl;
			}
		}
			cout<<"��"<<count<<"�ֵ��Ⱥ���������еĽ�����"<<endl;
    	ca2.showQueue();
    	count++;
	}
	cout<<"�ܵ�ִ��ʱ��Ϊ:"<<time<<endl;
	cout<<endl;
	
  system("pause");
	return 0;
}