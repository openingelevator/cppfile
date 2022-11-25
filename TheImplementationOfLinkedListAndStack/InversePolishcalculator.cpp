#include<iostream>
#include<stack>
#include<list>
#include<string>
#include<vector>
using namespace std;
//前缀表达式又叫波兰表达式，前缀表达式操作符位于操作数之前
// 例如（3+4）*5-6对应的前缀表达式为- * + 3 4 5 6
//前缀表达式求值，从右至左扫描表达式，遇到数字时，将数字压入堆栈，遇到运算符时，弹出栈顶的两个数对他们做相应运算
//并将结果入栈，重复上述过程直到表达式最左端，最后运算得出的值即为表达式的结果

//后缀表达式又叫逆波兰表达式，运算符位于操作数之后
//例如（3+4）*5-6对应的后缀表达式为3 4 + 5 * 6 -
//后缀表达式求值，从左至右扫描表达式，遇到数字时，将数字压入堆栈，遇到运算符时，弹出栈顶的两个数对他们做相应运算
//并将结果入栈，重复上述过程直到表达式最右端，最后运算得出的值即为表达式的结果

// 中缀表达式转后缀表达式
// 1.初始化两个栈，运算符栈s1和存储中间结果的栈s2
// 2.从左至右扫描中缀表达式
// 3.遇到操作数时，将其压入s2
// 4.遇到运算符时，比较其与s1栈顶元素的优先级
// （1）如果s1为空，或栈顶运算符为左括号"("，这直接将此运算符入栈
// （2）否则，若优先级比栈顶运算符的高，也将此运算符压入s1
// 否则，将s1栈顶的运算符弹出并压入s2中，再次转入（4-1）与s1中的新的栈顶的运算符比较
// 5.遇到括号时：
// （1）如果是左括号，则直接压入s1
// （2）如果是右括号，则依次弹出s1栈顶的运算符，并压入s2，直到遇到左括号为止，此时将这一对括号丢弃
// 6.重复步骤2-5直到表达式最左边
// 7.将s1中剩余的运算符依次弹出并压入s2，依次弹出s2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式

//返回运算符优先级
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
//判断是不是一个运算符
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
		//先将对应的中缀表达式切割为数字与符号
		int index = 0;
		string str;//对多位数的拼接
		char c;//每遍历一个字符就放入到c
		while (index < infixExpression.length())
		{
			//如果c是一个非数字，就直接加入到arrayList中
			if ((c=infixExpression.at(index)) < 48 || (c=infixExpression.at(index))>57){
				string temp = "";
				temp += c;
				arrayList.push_back(temp);
				index++;
			}else{
				//如果c是一个数字，需要考虑多位数的问题
				//先将str置空
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
		//测试输出代码
		for (auto i : arrayList)
		{
			cout << i << ",";
		}
	}
	vector<string> convert()
	{
		//遍历arrayList
		for (string item : arrayList)
		{
			//如果是一个数则直接压入stack2
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
				//将左括号弹出，消除一对小括号
				stack1.pop();
			}
			else
			{
				//当item的优先级小于等于stack1栈顶运算符的优先级，将stack1栈顶的运算符弹出并加入到stack2中，再次与stack1中新的栈顶运算符相比较
				while (stack1.size() != 0&&operPriority(stack1.top())>= operPriority(item))
				{
					stack2.push_back(stack1.top());
					stack1.pop();
				}
				stack1.push(item);
			}

		}
		//将stack1中剩余的运算符加入stack2中
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
	//存放中缀表达式对应的内容
	vector<string>arrayList;
	//存储符号的栈
	stack<string>stack1;
	//存储中间结果的栈
	vector<string>stack2;
};
int cal(int num1, int num2, string oper)
{
	int res = 0;//用于存放计算结果
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
		//遍历expression
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
					cout << "运算符有误" << endl;
					return -1;
				}else
				{
					numStack.push(res);
				}
			}
		}
		//最后留在numStack中的就是运算结果
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
	//创建数栈
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