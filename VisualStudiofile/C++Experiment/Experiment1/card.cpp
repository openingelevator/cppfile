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
		cout << "µÚ" << i + 1 << "ÕÅÅÆÎª    " << deckCard.dealCard().tostring() << endl;
		i++;
	}
	return 0;
}