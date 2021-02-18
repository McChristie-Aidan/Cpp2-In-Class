v#include "Deck.h"

#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

Deck::Deck()
{
	this->m_cards = new vector<Card*>();
    createDeck();
}

Deck::~Deck()
{
    delete this->m_cards;
}

vector<Card*>* Deck::get_cards()
{
    this->shuffle();
    return this->m_cards;
}

void Deck::printCard(int i)
{
    Card* c = (*m_cards)[i];
    cout << c->Face << " of " << c->Suit << " : Value of " << c->cardValue << endl << endl;
}

void Deck::createDeck()
{
	//this deck instantiation code was adopted from a forum online.
	//feels better than having to type out each card.
	int New_Suit = 0;
	string faces[6] = { "Ace", "Nine", "Ten", "Jack", "Queen", "King" };
	string suits[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
	int CardValue[6] = { 1, 1, 1, 1, 1, 1 };

	for (int x = 0; x < 52; x++)
	{
		string f = faces[x % 6];
		string s = suits[New_Suit];
		int p = CardValue[x % 6];
		Card* c = new Card(f,s,p);
		this->m_cards->push_back(c);
		
		//just for making sure the deck gets made
		/*for (int x = 0; x < 6; x++)
		{
			cout << c->Face << " of " << c->Suit << " : Value of " << c->cardValue << endl;
		}*/

		if ((x + 1) % 6 == 0) 
		{
			New_Suit++;
		}
	}
}

void Deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->m_cards->begin(), this->m_cards->end(), std::default_random_engine(seed));
}