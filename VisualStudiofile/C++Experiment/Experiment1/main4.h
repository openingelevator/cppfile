#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
class Card
{
	friend class DeckofCards;
public:
	Card(int a, int b)
	{
		suit = a;
		face = b;
	}
	string tostring()
	{
		string s = "0f";
		return (m_suit[suit]+s+m_face[face]);
	}
private:
	int suit;
	int face;
	static string m_suit[4];
	static string m_face[13];
};
string Card::m_suit[4] = { "Heart","Diamond","Club","Spades" };
string Card::m_face[13] = { "Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };

class DeckofCards
{
public:
	DeckofCards()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				Card c(i, j);
				deck.push_back(c);
			}
		}
		
	}
	void shuffle()
	{
		srand(static_cast<unsigned int>(time(0)));
		int i = 0;
		int j = 0;
		for (int card = 51; card >=0; card--)
		{
			i = card;
			j = rand() % (card + 1);
			Card temp(0,0);
			temp.face = deck[i].face;
			deck[i].face = deck[j].face;
			deck[j].face = temp.face;
			temp.suit = deck[i].suit;
			deck[i].suit = deck[j].suit;
			deck[j].suit = temp.suit;
		}
	}
	Card dealCard()
	{
		currentCard++;
		return deck[currentCard];
	}
	bool moreCards()
	{
		if (currentCard >= 51)
		{
			return true;
		}
		else
			return false;
	}
	int currentCard = -1;
private:
	vector<Card>deck;
	
};