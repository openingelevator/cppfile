#include"Card.h"
#include<iostream>
using namespace std;
int main()
{
	DeckofCards deckCard;
	deckCard.shuffle();
	int i = 0;
	while (!deckCard.moreCards())
	{
		cout << "��" << i + 1 << "����Ϊ    " << deckCard.dealCard().tostring() << endl;
		i++;
	}
	return 0;
}