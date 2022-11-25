#include<iostream>
#include<stack>
#include<list>
#include<string>
#include<vector>
using namespace std;
//ǰ׺���ʽ�ֽв������ʽ��ǰ׺���ʽ������λ�ڲ�����֮ǰ
// ���磨3+4��*5-6��Ӧ��ǰ׺���ʽΪ- * + 3 4 5 6
//ǰ׺���ʽ��ֵ����������ɨ����ʽ����������ʱ��������ѹ���ջ�����������ʱ������ջ��������������������Ӧ����
//���������ջ���ظ���������ֱ�����ʽ����ˣ��������ó���ֵ��Ϊ���ʽ�Ľ��

//��׺���ʽ�ֽ��沨�����ʽ�������λ�ڲ�����֮��
//���磨3+4��*5-6��Ӧ�ĺ�׺���ʽΪ3 4 + 5 * 6 -
//��׺���ʽ��ֵ����������ɨ����ʽ����������ʱ��������ѹ���ջ�����������ʱ������ջ��������������������Ӧ����
//���������ջ���ظ���������ֱ�����ʽ���Ҷˣ��������ó���ֵ��Ϊ���ʽ�Ľ��

// ��׺���ʽת��׺���ʽ
// 1.��ʼ������ջ�������ջs1�ʹ洢�м�����ջs2
// 2.��������ɨ����׺���ʽ
// 3.����������ʱ������ѹ��s2
// 4.���������ʱ���Ƚ�����s1ջ��Ԫ�ص����ȼ�
// ��1�����s1Ϊ�գ���ջ�������Ϊ������"("����ֱ�ӽ����������ջ
// ��2�����������ȼ���ջ��������ĸߣ�Ҳ���������ѹ��s1
// ���򣬽�s1ջ���������������ѹ��s2�У��ٴ�ת�루4-1����s1�е��µ�ջ����������Ƚ�
// 5.��������ʱ��
// ��1������������ţ���ֱ��ѹ��s1
// ��2������������ţ������ε���s1ջ�������������ѹ��s2��ֱ������������Ϊֹ����ʱ����һ�����Ŷ���
// 6.�ظ�����2-5ֱ�����ʽ�����
// 7.��s1��ʣ�����������ε�����ѹ��s2�����ε���s2�е�Ԫ�ز���������������Ϊ��׺���ʽ��Ӧ�ĺ�׺���ʽ

//������������ȼ�
int operPriority(string oper)
{
	int temp = 0;
	if (oper == "+" || oper == "-")
	{
		temp = 1;
	}
	else if (oper == "*" || oper == "/")
	{
		temp = 2;
	}
	return temp;
}
//�ж��ǲ���һ�������
bool isOper(string val)
{
	return val == "+" || val == "-" || val == "*" || val == "/";
}
class convertExpression
{
public:
	convertExpression(string exp)
	{
		this->infixExpression = exp;
	}
	void toInfixExpressionList()
	{
		//�Ƚ���Ӧ����׺���ʽ�и�Ϊ���������
		int index = 0;
		string str;//�Զ�λ����ƴ��
		char c;//ÿ����һ���ַ��ͷ��뵽c
		while (index < infixExpression.length())
		{
			//���c��һ�������֣���ֱ�Ӽ��뵽arrayList��
			if ((c=infixExpression.at(index)) < 48 || (c=infixExpression.at(index))>57){
				string temp = "";
				temp += c;
				arrayList.push_back(temp);
				index++;
			}else{
				//���c��һ�����֣���Ҫ���Ƕ�λ��������
				//�Ƚ�str�ÿ�
				str = "";
				while (index < infixExpression.length() &&
					(c = infixExpression.at(index)) >= 48 && (c = infixExpression.at(index)) <= 57)
				{
					str += c;
					index++;
				}
				arrayList.push_back(str);
			}
		}
		//�����������
		for (auto i : arrayList)
		{
			cout << i << ",";
		}
	}
	vector<string> convert()
	{
		//����arrayList
		for (string item : arrayList)
		{
			//�����һ������ֱ��ѹ��stack2
			if (item != "(" && item != ")" &&!isOper(item))
			{
				stack2.push_back(item);
			}
			else if (item == "(")
			{
				stack1.push(item);
			}
			else if (item == ")")
			{
				while (!(stack1.top()=="("))
				{
					stack2.push_back(stack1.top());
					stack1.pop();
				}
				//�������ŵ���������һ��С����
				stack1.pop();
			}
			else
			{
				//��item�����ȼ�С�ڵ���stack1ջ������������ȼ�����stack1ջ������������������뵽stack2�У��ٴ���stack1���µ�ջ���������Ƚ�
				while (stack1.size() != 0&&operPriority(stack1.top())>= operPriority(item))
				{
					stack2.push_back(stack1.top());
					stack1.pop();
				}
				stack1.push(item);
			}

		}
		//��stack1��ʣ������������stack2��
		while(stack1.size()!=0)
		{
			stack2.push_back(stack1.top());
			stack1.pop();
		}
		for (auto i : stack2)
		{
			cout << i << ",";
		}
		return stack2;
	}

private:
	string infixExpression;
	//�����׺���ʽ��Ӧ������
	vector<string>arrayList;
	//�洢���ŵ�ջ
	stack<string>stack1;
	//�洢�м�����ջ
	vector<string>stack2;
};
int cal(int num1, int num2, string oper)
{
	int res = 0;//���ڴ�ż�����
	if (oper == "+")
	{
		res = num1 + num2;
	}else if(oper=="-")
	{
		res = num1 - num2;
	}else if (oper == "*")
	{
		res = num1 * num2;
	}else if (oper == "/")
	{
		res = num1 / num2;
	}
	else
	{
		return -10000;
	}
	return res;
}
void Tokenize(const string& str, vector<string>& tokens, const string& delimiters)
{
	// Skip delimiters at beginning.
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	string::size_type pos = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}
int stringToNum(string exp)
{
	int integer = 0;
	for (int i = 0; i < exp.length(); i++)
	{
		integer = 10 * integer + (exp[i] - 48);
	}
	return integer;
}
class Calculator
{
public:
	Calculator(vector<string >exp)
	{
		this->expression.resize(exp.size());
		this->expression.assign(exp.begin(),exp.end());
	}
	int result()
	{
		//����expression
		for (auto i : expression)
		{
			if (!isOper(i))
			{
				int num = stringToNum(i);
				this->numStack.push(num);
			}
			else
			{
				int num2 = this->numStack.top();
				this->numStack.pop();
				int num1 = this->numStack.top();
				this->numStack.pop();
				int res = cal(num1, num2, i);
				if (res == -10000) {
					cout << "���������" << endl;
					return -1;
				}else
				{
					numStack.push(res);
				}
			}
		}
		//�������numStack�еľ���������
		return this->numStack.top();
	}
	void print()
	{
		for (auto i : this->expression)
		{
			cout << i << ",";
		}
	}
private:
	vector<string>expression;
	//������ջ
	stack<int> numStack;
};

int main()
{

	string exp = "10+(2+3)*4-5";
	convertExpression cons(exp);
	cons.toInfixExpressionList();
	cout << endl;
	vector<string>arrayList=cons.convert();
	cout << endl;
 //   string suffixExpression = "4 5 * 8 - 60 + 8 2 / + ";
 //   Tokenize(suffixExpression, arrayList, " ");
    Calculator cal(arrayList);
 //   cal.print();
    cout<<cal.result();
	system("pause");
	return 0;
}