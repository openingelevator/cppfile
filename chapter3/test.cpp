#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
   
    int n=1;
    //clock_t为cpu时钟计时单元数
    clock_t start,finish;
    for(int times=0;times<3;times++)
    {
        //clock函数返回当前cpu时钟计时单元数
        start=clock();
         int sum=0;
        
        //此处为可替换的循环...分别代入(a)(b)(c)(d)(e)(f)
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
        
    cout<<"当n="<<n<<" sum="<<sum<<endl;
    // cout<<setprecision(10)<<fixed;
    // cout<<"程序时间消耗为"<<double(finish-start)/CLOCKS_PER_SEC<<endl;
    
    n*=10;
    }
    system("pause");
    return 0;
}