// player.cpp
#include "player.h"
#include "motown.h"
#include <iostream>
#include <string>

using namespace std;
using std::string;

Player::Player()
{
	tag = "";
	sponsor = "";
	playerMain = 0;
	wins = 0;
	losses = 0;
}

Player::Player(string _tag, string _sponsor, int _main, int _win, int _lose)
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
	if (numGames == 0) return 0;
	else return (float)(wins / numGames) * 100;
}

void Player::print()
{
	if (sponsor != "")
	{
		belPrint(sponsor);
		cout << " | ";
	}
	if (tag != "")
	{
		belPrintLine(tag);
		belPrint("Character: ");
		belPrintLine(characters2[playerMain]);
		belPrint(wins);
		belPrint(" wins, ");
		belPrint(losses);
		belPrintLine(" losses");
		belPrint("Win rate: ");
		belPrint(winRate());
		belPrintLine("%");
		belPrintLine("");
	}
	else
	{
		belPrintLine("No such player was found.");
	}
}

void Player::print(int n)
{
	if (sponsor != "")
	{
		belPrint(sponsor);
		cout << " | ";
	}
	if (tag != "")
	{
		belPrint(tag);
		belPrint(" (ID - ");
		belPrint(n);
		belPrintLine(")");
		belPrint("Character: ");
		belPrintLine(characters2[playerMain]);
		belPrint(wins);
		belPrint(" wins, ");
		belPrint(losses);
		belPrintLine(" losses");
		belPrint("Win rate: ");
		belPrintLine(winRate());
		belPrintLine("");
	}
	else
	{
		belPrintLine("No such player was found.");
	}
}

void Player::addWins(int win)
{
	wins += win;
}

void Player::addLosses(int lose)
{
	losses += lose;
}

void Player::changeName(string n)
{
	tag = n;
}

void Player::changeSponsor(string s)
{
	sponsor = s;
}

void Player::set(string _tag, string _sponsor, int _main, int _win, int _lose)
{
	tag = _tag;
	sponsor = _sponsor;
	playerMain = _main;
	wins = _win;
	losses = _lose;
}

PlayerDB::PlayerDB()
{
	for (int a = 0; a < 200; a++)
	{
		players[a] = Player();
	}
}
void PlayerDB::textParser()
{
	//Gets text input to activate player-related functions.
	cin.clear();
	string input = "";
	belPrint(">");
	getline(std::cin, input);
	//belIgnore();
	system("CLS");
	if (input == "help")
	{
		belPrintLine("- add - add new player to database");
		belPrintLine("- show - show one player's stats");
		belPrintLine("- showall - show all players' stats");
		belPrintLine("- find - search for players by tag");
		belPrintLine("- edit - edit one player's stats");
	}
	if (input == "add")
	{
		addPlayer();
	}
	if (input == "show")
	{
		belPrint("Enter player numerical ID >");
		int show = 0;
		cin >> show;
		belPrintLine("");
		belIgnore();
		showPlayer(show);
	}
	if (input == "edit")
	{
		belPrint("Enter player numerical ID >");
		int edit = 0;
		cin >> edit;
		belPrintLine("");
		belIgnore();
		showPlayer(edit);
		if (players[edit].tag != "")
		{
			belPrintLine("");
			belPrintLine("Edit options:");
			belPrintLine(" - tag - Change player's tag");
			belPrintLine(" - sponsor - Change player's team/sponsor");
			belPrintLine(" - win - Add wins to player");
			belPrintLine(" - loss - Add losses to player");
			players[edit].edit();
		}
	}
	if (input == "showall")
	{
		showPlayers();
	}
	if (input == "find")
	{
		string find = "";
		belPrint("Enter player's tag. All matching results will be shown.");
		getline(std::cin, find);
		belPrintLine("");
		belIgnore();
		findPlayer(find);

	}
}
void Player::edit()
{
	string input2 = "";
	belPrint(">");
	getline(std::cin, input2);
	if (input2 == "tag")
	{
		//Prompts for a new tag, which then replaces the old one.
		string newTag = "";
		belPrint("Enter new tag >");
		getline(std::cin, newTag);
		if (newTag != "")
		{
			changeName(newTag);
		}
	}
	if (input2 == "sponsor")
	{
		//Prompts for a new team name, which then replaces the old one.
		string newTeam = "";
		belPrint("Enter new team/sponsor >");
		getline(std::cin, newTeam);
		if (newTeam != "")
		{
			changeSponsor(newTeam);
		}
	}
	if (input2 == "win")
	{
		int win = 0;
		belPrintLine("How many wins?");
		cin >> win;
		addWins(win);
	}
	if (input2 == "loss")
	{
		int loss = 0;
		belPrintLine("How many losses?");
		cin >> loss;
		addLosses(loss);
	}
	if (input2 == "back")
	{
		return;
	}
	//cin.ignore(INT_MAX, '\n');
}
void PlayerDB::addPlayer()
{
	string name = "";
	string sponsor = "";
	int main;
	belPrint("Player name >");
	getline(std::cin,name);
	belPrintLine("");
	belPrint("Player team/sponsor >");
	getline(std::cin, sponsor);
	belPrintLine("");
	belPrint("Player main >");
	cin >> main;
	characters mainPick = static_cast<characters>(main);
	belPrintLine("");
	belIgnore();
	bool foo = false;
	for (int c = 0; c < 200; c++)
	{
		if (foo) break;
		if (players[c].tag == "")
		{
			foo = true;
			players[c].set(name, sponsor, mainPick, 0, 0);
			belPrint("Player ");
			belPrint(name);
			belPrintLine(" added to database.");
			break;
		}
	}
}
void PlayerDB::findPlayer(string input)
{
	int matches = 0;
	for (int p = 0; p < 200; p++)
	{
		if (players[p].tag == input)
		{
			matches++;
			players[p].print();
		}
	}
	belPrint("Found ");
	belPrint(matches);
	belPrintLine(" matches.");
}
void PlayerDB::showPlayer(int num)
{
	if (players[num].tag != "")
	{
		belPrint("Player ID - ");
		belPrintLine(num);
	}
	players[num].print();
}
void PlayerDB::showPlayers()
{
	for (int p = 0; p < 200; p++)
	{
		if (players[p].tag != "")
		{
			belPrint("Player ID - ");
			belPrintLine(p);
			players[p].print();
		}
	}
	
}

Player PlayerDB::player(int num)
{
	return players[num];
}