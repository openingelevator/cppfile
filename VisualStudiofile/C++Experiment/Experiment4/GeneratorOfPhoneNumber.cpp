#include<iostream>
#include<fstream>
using namespace std;
void translation(ofstream& ofs,char* word, char* num,int position)
{
	if (position == 7)
	{
		for (int i = 0; i < 7; i++)
		{
			if (i == 6) { ofs << word[i] << '\n'; break; }
			ofs << word[i];
		
		}
		return;
	}
	else
	{
		switch (num[position])
		{
		case '2':
			word[position] = 'A';
			translation(ofs, word, num, position + 1);
			word[position] = 'B';
			translation(ofs, word, num, position + 1);
			word[position] = 'C';
			translation(ofs, word, num, position + 1);
			break;
		case '3':
			word[position] = 'D';
			translation(ofs, word, num, position + 1);
			word[position] = 'E';
			translation(ofs, word, num, position + 1);
			word[position] = 'F';
			translation(ofs, word, num, position + 1);
			break;
		case '4':
			word[position] = 'G';
			translation(ofs, word, num, position + 1);
			word[position] = 'H';
			translation(ofs, word, num, position + 1);
			word[position] = 'I';
			translation(ofs, word, num, position + 1);
			break;
		case '5':
			word[position] = 'J';
			translation(ofs, word, num, position + 1);
			word[position] = 'K';
			translation(ofs, word, num, position + 1);
			word[position] = 'L';
			translation(ofs, word, num, position + 1);
			break;
		case '6':
			word[position] = 'M';
			translation(ofs, word, num, position + 1);
			word[position] = 'N';
			translation(ofs, word, num, position + 1);
			word[position] = 'O';
			translation(ofs, word, num, position + 1);
			break;
		case '7':
			word[position] = 'P';
			translation(ofs, word, num, position + 1);
			word[position] = 'R';
			translation(ofs, word, num, position + 1);
			word[position] = 'S';
			translation(ofs, word, num, position + 1);
			break;
		case '8':
			word[position] = 'T';
			translation(ofs, word, num, position + 1);
			word[position] = 'U';
			translation(ofs, word, num, position + 1);
			word[position] = 'V';
			translation(ofs, word, num, position + 1);
			break;
		case '9':
			word[position] = 'W';
			translation(ofs, word, num, position + 1);
			word[position] = 'X';
			translation(ofs, word, num, position + 1);
			word[position] = 'Y';
			translation(ofs, word, num, position + 1);
			break;
		default:
			break;
		}
	}
}
int main()
{
	ofstream ofs;
	ofs.open("number.txt", ios::out);
	char word[7];
	char num[7];
	for (int i = 0; i < 7; i++)
	{
		num[i] = cin.get();
	}
	translation(ofs,word, num, 0);
	ofs.close();
	return 0;
}