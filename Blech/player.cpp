// player.cpp
#include "player.h"
#include "motown.h"
#include <iostream>

Player::Player()
{
	tag = 0;
	sponsor = 0;
	playerMain = 0;
	wins = 0;
	losses = 0;
}

Player::Player(char _tag[], char _sponsor[], int _main, int _win, int _lose)
{
	tag = _tag;
	sponsor = _sponsor;
	playerMain = _main;
	wins = _win;
	losses = _lose;
}

float Player::winRate()
{
	int numGames = wins + losses;
	return (float)(wins / numGames) * 100;
}

void Player::print()
{
	if (sponsor != 0)
	{
		belPrint(sponsor);
		std::cout << " | ";
	}
	if (tag != 0)
	{
		belPrintLine(tag);
	}
	belPrint("Character: ");
	belPrintLine(characters2[playerMain]);
	belPrint(wins);
	belPrint("wins, ");
	belPrint(losses);
	belPrintLine("losses");
}


PlayerDB::PlayerDB()
{
	for (int a = 0; a < 200; a++)
	{
		players[a] = Player();
	}
}

void PlayerDB::addPlayer()
{
	char name[20];
	char sponsor[20];
	int main;
	belPrint("Player name >");
	std::cin.getline(name, 20);
	belPrintLine("");
	belPrint("Player sponsor >");
	std::cin.getline(sponsor, 20);
	belPrintLine("");
	belPrint("Player main >");
	std::cin >> main;
	characters mainPick = static_cast<characters>(main);
	belPrintLine("");
	bool foo = false;
	for (int c = 0; c < 200; c++)
	{
		if (foo) break;
		if (players[c].tag == 0)
		{
			foo = true;
			players[c] = Player{ name, sponsor, mainPick, 0, 0 };
			continue;
		}
	}
	belPrintLine("flushed emoji");
}

void PlayerDB::showPlayer(int num)
{
	if (players[num].tag != 0)
	players[num].print();
}

Player PlayerDB::player(int num)
{
	return players[num];
}