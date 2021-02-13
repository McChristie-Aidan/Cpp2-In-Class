#pragma once
#include "Player.h"
#include "Deck.h"
#include <vector>

using std::vector;

class Euchre
{
private:
	//i have a lot of functions here maybe i should make a util class
	void playEuchre(Player* player, Player* dealer, Deck* d);
	void printCard(vector<Card*>* cardPile, int i);
	void drawCard(Player* playerWhoDraws, vector<Card*>* deckToDrawFrom, int timesToDraw);
	void printHand(Player* player);
	string getPlayerName();
public:
	Euchre();
	~Euchre();
	
};