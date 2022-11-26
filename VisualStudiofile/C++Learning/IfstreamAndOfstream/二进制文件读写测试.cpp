#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct course
{
	char num[4];
	string cname;
	int hour;
	int credit;
};
void createBinaryFile(char* filetxt, char* fileData)
{
	ifstream input(filetxt,ios::in);
	ofstream output(fileData,ios::out|ios::binary);
    string temp;
    getline(input, temp);
	getline(input, temp);
	cout << temp << endl;
	course acourse;
	while (input.peek()!=EOF)
	{
		
		for (int i = 0; i < 4; i++)
			input >> acourse.num[i];

		input >> acourse.cname;
		cout << acourse.cname << endl;

		char c = 0;
		while (c < '0' || c>'9')
			input >> c;
		acourse.hour = (c - '0') * 10;
		input >> c;
		acourse.hour += (c - '0');

		input >> acourse.credit;

		for (int i = 0; i < 4; i++)
		  output << acourse.num[i];

		output << acourse.hour;
		output << acourse.credit;
	}
	input.close();
	output.close();
}
int main()
{
	char f1name[20] = "text.txt";
	char f2name[20] = "output.dat";
	createBinaryFile(f1name, f2name);
	return 0;
}