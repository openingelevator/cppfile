#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
   
    int n=1;
    //clock_tΪcpuʱ�Ӽ�ʱ��Ԫ��
    clock_t start,finish;
    for(int times=0;times<3;times++)
    {
        //clock�������ص�ǰcpuʱ�Ӽ�ʱ��Ԫ��
        start=clock();
         int sum=0;
        
        //�˴�Ϊ���滻��ѭ��...�ֱ����(a)(b)(c)(d)(e)(f)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i*i;j++)
            {
                if(j%i==0)
                {
                for(int k=0;k<j;k++)
                {
                    sum++;
                }
                }
            }
        }

        finish=clock();
        
    cout<<"��n="<<n<<" sum="<<sum<<endl;
    // cout<<setprecision(10)<<fixed;
    // cout<<"����ʱ������Ϊ"<<double(finish-start)/CLOCKS_PER_SEC<<endl;
    
    n*=10;
    }
    system("pause");
    return 0;
}