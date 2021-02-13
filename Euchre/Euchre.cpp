#include "Euchre.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

Deck* deck;
Player* player1;
Player* player2;
Player* player3;
Player* player4;
string dealerName = "Dealer";
string playerName = "Player";
vector<Card*>* cardPile;

Euchre::Euchre()
{
	Deck* deck = new Deck();
    
    vector<Card*>* player1Hand = new vector<Card*>();
    vector<Card*>* player2Hand = new vector<Card*>();
    vector<Card*>* player3Hand = new vector<Card*>();
    vector<Card*>* player4Hand = new vector<Card*>();

    player1 = new Player(getPlayerName(), player1Hand);
    player2 = new Player(getPlayerName(), player2Hand);
    player3 = new Player(getPlayerName(), player3Hand);
    player4 = new Player(getPlayerName(), player4Hand);

    //TODO Deal hands 
    vector<Card*>* cardPile = deck->get_cards();

    drawCard(player1, cardPile, 5);
    drawCard(player2, cardPile, 5);
    drawCard(player3, cardPile, 5);
    drawCard(player4, cardPile, 5);

    printHand(player1)
    printHand(player2)
    printHand(player3)
    printHand(player4)

}

//takes a card from a deck and puts it into a players hand
void Euchre::drawCard(Player* playerWhoDraws, vector<Card*>* deckToDrawFrom, int timesToDraw)
{
	int t = timesToDraw;
	vector<Card*>* d = deckToDrawFrom;
	Player* p = playerWhoDraws;
	for (int i = 0; i < t; i++)
	{
		Card* c = d->front();
		p->hand->push_back(c);
		d->erase(d->begin());
	}
}

//mainly for debug
void Euchre::printCard(vector<Card*>* cardPile, int i)
{
	Card* c = (*cardPile)[i];
	cout << c->Face << " of " << c->Suit << " : Value of " << c->cardValue << endl << endl;
}

//prints the hand of the specified player
void Euchre::printHand(Player* player)
{
	Player* p = player;
	cout << player->name << "'s hand:" << endl;
	for (size_t i = 0; i < p->hand->size(); i++)
	{
		Card* c = (*p->hand)[i];
		cout << c->Face << " of " << c->Suit << " : Value of " << c->cardValue << endl;
	}
}

//takes input to set player name
string Euchre::getPlayerName()
{
	string name;
	cout << "What is your name?" << endl << endl;
	cin >> name;
	cout << endl;

	return name;
}
