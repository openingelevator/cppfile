#include<iostream>
#include<string>
#include<vector>
using namespace std;

string convert(string s, int numRows) {

    if(numRows==1)
    {
        return s;
    }
    int len=s.length();
    int offset=0;
    if(len%(2*numRows-2)<=numRows)
    {
        offset=1;
    }else
    {
        offset=1+(len%(2*numRows-2)-numRows);
    }
    int column=(len/(2*numRows-2))*(numRows-1)+offset;
    vector<vector<char>>v;
    vector<char>v1;
    for(int i=0;i<numRows;i++)
    {
        v1.clear();
        for(int i=0;i<column;i++)
        {
        v1.push_back('0');
        }
        v.push_back(v1);
    }
    int index=0;
    for(int c=0;c<column;c++)
    {
        for(int r=0;r<numRows;r++)
        {
            if(c%(numRows-1)==0)
            {
                if(index<len)
                {
                    v[r][c]=s[index];
                    index++;
                }
                else{break;}
            }else if(c%(numRows-1)+r+1==numRows)
            {
                v[r][c]=s[index];
                index++;
                break;
            }
        }
    }
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    string res;
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(v[i][j]!='0')
            {
                res+=v[i][j];
            }
        }
    }
    return res;
}

int main()
{
    string str="PAYPALISHIRING";
    cout<<convert(str,1);
    system("pause");
    return 0;
}