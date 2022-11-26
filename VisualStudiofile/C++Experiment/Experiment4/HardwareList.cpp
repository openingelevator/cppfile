#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class Hareware
{
public:
	Hareware(int series=0, string tool="    ", int Num=0, double Price=0.0)
	{
		this->seriesNumber = series;
		this->setToolName(tool);
		this->num = Num;
		this->price = Price;
	
	}
	void setToolName(string tool)
	{
		const char* temp = tool.data();
		int length = tool.size();
		length = (length < 15 ? length : 14);
		strncpy_s(this->toolName, temp, length);
		this->toolName[length] = '\0';
	}
	int seriesNumber;
	char toolName[15];
	int num;
	double price;
};
void outputLine(ostream & output, const Hareware & record)
{
	 output << left << setw(10) << record.seriesNumber
			   << setw(16) << record.toolName
		 << setw(11) << record.num
		 << setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.price<< endl;
} 
void print(fstream& readFile)
{
	ifstream ifs("hardware.dat", ios::in|ios::binary);
	if (!ifs) {
		cerr << "File cannot open" << endl; exit(EXIT_FAILURE);
	}
	cout << left << setw(10) << "��¼��" << setw(16)
		<< "��������" << setw(11) << "����" << left
		<< setw(10) << right << "�۸�" << endl;
	Hareware H;
	for (int i = 0; i < 100; i++)
	{
		readFile.seekg(i * sizeof(Hareware));
		readFile.read(reinterpret_cast<char*>(&H), sizeof(Hareware));
		if (H.seriesNumber != 0)
			outputLine(cout, H);
	}
	ifs.close();
}
void updateRecord(fstream&updateFile)
{
	int record;
	cout << "��������Ҫ���µļ�¼" << endl;
	do
	{
		cin >> record;
	} while (record < 0 || record>100);
	updateFile.seekg((record - 1) * sizeof(Hareware));
	Hareware h1;
	updateFile.read(reinterpret_cast<char*>(&h1), sizeof(Hareware));
	if (h1.seriesNumber == 0)
	{
		char tool[15];
		int Num;
		double Price;
		cout << "�������µĹ��ߣ�������۸�" << endl;
		cin >> tool >> Num >> Price;
		h1.setToolName(tool);
		h1.num = Num;
		h1.price = Price;
		updateFile.seekp((record - 1) * sizeof(Hareware));
		updateFile.write(reinterpret_cast<const char*>(&h1), sizeof(Hareware));

	}
	else
	{
		cerr << "����������" << endl;
	}
	

}
void Delete(fstream& deleteRecord)
{
	int record;
	cout << "��������Ҫɾ���ļ�¼" << endl;
	do
	{
		cin >> record;
	} while (record < 0 || record>100);
	deleteRecord.seekg((record - 1) * sizeof(Hareware));
	Hareware h1;
	deleteRecord.read(reinterpret_cast<char*>(&h1), sizeof(Hareware));
	if (h1.seriesNumber != 0)
	{
		Hareware blankh;
		deleteRecord.seekp((record - 1) * sizeof(Hareware));
		deleteRecord.write(reinterpret_cast<const char*>(&blankh), sizeof(Hareware));
	}
	else
	{
		cerr << "����������" << endl;
	}
}
void AccessFile(fstream& fs)
{
	int sumOfRecord;
	cout << "������Ҫ��ӵļ�¼��" << endl;
	cin >> sumOfRecord;
	for (int i = 0; i < sumOfRecord; i++)
	{
		Hareware h;
		char tool[15];
		int Num;
		double Price;
		cout << "�������µĹ��ߣ�������۸�" << endl;
		cin >> tool >> Num >> Price;
		h.seriesNumber = i+1;
		h.setToolName(tool);
		h.num = Num;
		h.price = Price;
		fs.seekp((i) * sizeof(Hareware));
		fs.write(reinterpret_cast<const char*>(&h), sizeof(Hareware));
	}
}
int main()
{
	fstream fs;
	fs.open("hardware.dat", ios::out);
	fs.close();
	fs.open("hardware.dat", ios::out|ios::in|ios::binary);
	if (!fs)
	{
		cerr << "File could not opened" << endl;
		exit(EXIT_FAILURE);
	}
	int choice;
	Hareware H1;
	for (int i = 0; i < 100; i++)
	{
		fs.write(reinterpret_cast<const char*>(&H1), sizeof(Hareware));
	}
	cout << "���������ѡ��" << endl;
	cout << "1:��ӡ���м�¼" << endl;
	cout << "2:����ĳ����¼" << endl;
	cout << "3:ɾ��ĳ����¼" << endl;
	cout << "4:���������¼" << endl;
	cout << "5:�˳�����" << endl;
	while (true)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			print(fs);
			break;
		case 2:
			updateRecord(fs);
			break;
		case 3:
			Delete(fs);
			break;
		case 4:
			AccessFile(fs);
			break;
		case 5:
			exit(1);
			break;
		default:
			cerr << "Incorrect number" << endl;
			break;
		}
		fs.clear();
		
	}
	fs.close();
	return 0;
}