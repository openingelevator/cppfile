#include<iostream>
using namespace std;
//�����CPU��
class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};
//�����GPU��
class GPU
{
public:
	virtual void display() = 0;
};
//�����Memory��
class Memory
{
public:
	virtual void storage() = 0;
};
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	void display()
	{
		cout << "Intel��GPU��ʼ��ʾ" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel��Memory��ʼ�洢" << endl;
	}
};
class LenovoCPU:public CPU
{
public:

	void calculate()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};
class LenovoGPU :public GPU
{
public:
	void display()
	{
		cout << "Lenovo��GPU��ʼ��ʾ" << endl;
	}
}; 
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo��Memory��ʼ�洢" << endl;
	}
};
class Computer
{
public:
	Computer(CPU *cpu,GPU *gpu,Memory*memory)
	{
		m_cpu =cpu ;
		m_gpu =gpu;
		m_memory =memory;
	}
	//�ṩ�����������ͷ������������
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}

	}
	void dowork()
	{
		m_cpu->calculate();
		m_gpu->display();
		m_memory->storage();
	}

private:

	CPU* m_cpu;
	GPU* m_gpu;
	Memory* m_memory;

};
void test01()
{
	//��һ̨���Ե����
	CPU* intelCPU = new IntelCPU;
	GPU* intelGPU = new IntelGPU;
	Memory* intelMemory = new IntelMemory;
	//������һ̨����
	Computer* c1 = new Computer(intelCPU, intelGPU, intelMemory);
	c1->dowork();
	delete c1;
	//�����ڶ�̨����
	CPU* lenovoCPU = new LenovoCPU;
	GPU* lenovoGPU = new LenovoGPU;
	Memory* lenovoMemory = new LenovoMemory;
	Computer* c2 = new Computer(lenovoCPU, lenovoGPU, lenovoMemory);
	c2->dowork();
	delete c2;

}
int main()
{
	test01();
	return 0;
}