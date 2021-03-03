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
vector<Card*>* cardPile;

//takes a card from a deck and puts it into a players hand
void Euchre::drawCard(Player* playerWhoDraws, vector<Card*>* deckToDrawFrom, int timesToDraw)
{
	//debug for checking when some one takes a card from the deck
	//cout << playerWhoDraws->name << " drew a card" << endl;
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
	cout << player->name << "'s hand:" << endl;
	for (size_t i = 0; i < player->hand->size(); i++)
	{
		Card* c = player->hand->at(i);
		cout << c->Face << " of " << c->Suit << " : Value of " << c->cardValue << endl;
	}
	cout << player->name << "'s hand power is " << findHandPower(player) << endl << endl;
}

//this function only returns a number right now 
//it wont tell you which suit is prefered but i could change this by making a struct as the return type.
float Euchre::findHandPower(Player* player)
{
	vector<Card*>* hand = player->hand;

	//technical debt there has to be a better way to do this

	float diamonds;
	float hearts;
	float spades;
	float clubs;

	for (int i = 0; i < hand->size(); i++)
	{
		Card* c = (*hand)[i];
		//this is a really janky way to do this.
		//this switch will increase the hands power in each suit depending on each card.
		//I add the card value * .01 so that way the algorithm takes in account not only the suit but the value of the card
		//I have to multiply by .01 so that the agorithm cares more about the suit than the value. It's more of a tie breaker
		//it doesnt account for the jacks yet but I could tack that on their pretty easily
		if (c->Suit == "Diamonds")
		{
			diamonds += .1 + (c->cardValue * .01);
		}
		else if (c->Suit == "Hearts")
		{
			hearts += .1 + (c->cardValue * .01);
		}
		else if (c->Suit == "Spades")
		{
			spades += .1 + (c->cardValue * .01);
		}
		else if (c->Suit == "Clubs")
		{
			clubs += .1 + (c->cardValue * .01);
		}
	}
	
	float result = diamonds;

	//this finds the largest of the numbers and makes that the result.
	if (result < hearts)
	{
		result = hearts;
	}
	if (result < spades)
	{
		result = spades;
	}
	if (result < clubs)
	{
		result = clubs;
	}

	return result;
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

void Euchre::playEuchre()
{
    vector<Card*>* player1Hand = new vector<Card*>();
    vector<Card*>* player2Hand = new vector<Card*>();
    vector<Card*>* player3Hand = new vector<Card*>();
    vector<Card*>* player4Hand = new vector<Card*>();

	cout << "hands initialized" << endl << endl;

    player1 = new Player(getPlayerName(), player1Hand);
    player2 = new Player(getPlayerName(), player2Hand);
    player3 = new Player(getPlayerName(), player3Hand);
    player4 = new Player(getPlayerName(), player4Hand);

	cout << "players named and created" << endl << endl;

	Deck* deck = new Deck();
    vector<Card*>* cardPile = deck->get_cards();

	cout << "deck recieved" << endl << endl;

    drawCard(player1, cardPile, 5);
    drawCard(player2, cardPile, 5);
    drawCard(player3, cardPile, 5);
    drawCard(player4, cardPile, 5);

	cout << "hands delt" << endl << endl;

    printHand(player1);
    printHand(player2);
    printHand(player3);
    printHand(player4);
}

Euchre::Euchre()
{
	Euchre::playEuchre();
}