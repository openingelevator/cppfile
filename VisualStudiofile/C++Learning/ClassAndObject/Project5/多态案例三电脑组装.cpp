#include<iostream>
using namespace std;
//抽象的CPU类
class CPU
{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};
//抽象的GPU类
class GPU
{
public:
	virtual void display() = 0;
};
//抽象的Memory类
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
		cout << "Intel的CPU开始计算" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	void display()
	{
		cout << "Intel的GPU开始显示" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	void storage()
	{
		cout << "Intel的Memory开始存储" << endl;
	}
};
class LenovoCPU:public CPU
{
public:

	void calculate()
	{
		cout << "Lenovo的CPU开始计算" << endl;
	}
};
class LenovoGPU :public GPU
{
public:
	void display()
	{
		cout << "Lenovo的GPU开始显示" << endl;
	}
}; 
class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo的Memory开始存储" << endl;
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
	//提供析构函数，释放三个电脑零件
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
	//第一台电脑的零件
	CPU* intelCPU = new IntelCPU;
	GPU* intelGPU = new IntelGPU;
	Memory* intelMemory = new IntelMemory;
	//创建第一台电脑
	Computer* c1 = new Computer(intelCPU, intelGPU, intelMemory);
	c1->dowork();
	delete c1;
	//创建第二台电脑
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