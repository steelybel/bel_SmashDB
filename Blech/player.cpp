// player.cpp
#include "player.h"
#include "motown.h"
#include <vector>
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

//Allows user to update or correct information on a player.
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
			belPrintLine("");
			belPrint("Changed tag: ");
			belPrint(tag);
			changeName(newTag);
			belPrint(" -> ");
			belPrintLine(tag);
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
			belPrintLine("");
			belPrint("Changed team/sponsor of ");
			belPrint(tag);
			belPrint(" to ");
			belPrint(sponsor);
			belPrintLine(".");
		}
	}
	if (input2 == "main")
	{
		//Prompts for a new character, replacing the previous.
		string newMain = "";
		bool mainValid = false;
		while (!mainValid)
		{
			belPrint("Enter new main >");
			getline(std::cin, newMain);
			for (int c = 0; c < 26; c++)
			{
				if (newMain == characters2[c])
				{
					mainValid = true;
					playerMain = c;
					break;
				}

			}
			if (mainValid) break;
			else
			{
				belPrintLine("Not a valid character.");
			}
		}
		belPrintLine("");
		belPrint("Changed main of ");
		belPrint(tag);
		belPrint(" to ");
		belPrint(characters2[playerMain]);
		belPrintLine(".");
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
	belPrintLine("Melee-CircuitDB 1.0\nCopyright 2019 Bel Industries\nNo copyright intended");
	belPrintLine("");
	belPrintLine("Enter desired database size.");
	int dbSize = 0;
	std::cin >> dbSize;
	initArray(dbSize);
}

void PlayerDB::intro()
{
	belPrintLine("Melee-CircuitDB 1.0\nCopyright 2019 Bel Industries\nNo copyright intended");
	belPrintLine("");
	belPrintLine("Type 'help' for help!");
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
		belPrintLine(" - add		- add new player to database (using numerical ID)");
		belPrintLine(" - remove		- remove player from database (using numerical ID)");
		belPrintLine(" - show		- show one player's stats (using numerical ID)");
		belPrintLine(" - showall	- show all players' stats");
		belPrintLine(" - find		- search for players by tag (use this to quickly retrieve numerical IDs)");
		belPrintLine(" - edit		- edit one player's stats (using numerical ID)");
		belPrintLine(" - save		- save all data to text file");
	}
	if (input == "add")
	{
		addPlayer();
	}
	if (input == "remove")
	{
		belPrint("Enter player numerical ID >");
		int rem = 0;
		cin >> rem;
		belPrintLine("");
		belIgnore();
		showPlayer(rem);
		if (players[rem].tag != "")
		{
			belPrint("Are you sure you want to delete this player entry? (Y/N) >");
			string typein = "n";
			getline(std::cin, typein);
			if (typein == "y" || typein == "Y")
			{
				belPrintLine("");
				belPrint(players[rem].tag);
				belPrintLine(" removed from database.");
				removePlayer(rem);
			}
		}
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
			belPrintLine(" - tag		- Change player's tag");
			belPrintLine(" - sponsor	- Change player's team/sponsor");
			belPrintLine(" - main		- Change player's main character");
			belPrintLine(" - win		- Add wins to player");
			belPrintLine(" - loss		- Add losses to player");
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
		belPrint("Enter player tag. All matching results will be shown. >");
		getline(std::cin, find);
		belPrintLine("");
		findPlayer(find);

	}
	if (input == "save")
	{
		saveFile();
		belPrint("Database saved to ");
		belPrintLine(filename);
	}
}

void PlayerDB::addPlayer()
{
	//Initialize player values
	string name = "";
	string sponsor = "";
	string main_ = "";
	bool mainValid = false;
	int main;

	//Take user input
	belPrint("Player name >");
	getline(std::cin,name);
	belPrintLine("");
	belPrint("Player team/sponsor >");
	getline(std::cin, sponsor);
	belPrintLine("");

	//If user types in a character not available, they are prompted again.
	while (mainValid == false)
	{
		belPrint("Player main (case sensitive) >");
		getline(std::cin, main_);
		for (int c = 0; c < 26; c++)
		{
			if (main_ == characters2[c])
			{
				mainValid = true;
				main = c;
				break;
			}
			
		}
		if (mainValid) break;
		else
		{
			belPrintLine("Not a valid character.");
		}
	}

	belPrintLine("");
	players.insert(players.size, new Player(name, sponsor, main, 0, 0));
	belPrint("Player ");
	belPrint(name);
	belPrintLine(" added to database.");
}

//Empties a player entry, effectively deleting them.
//The index is freed, so the next player added will take their place.
void PlayerDB::removePlayer(int player)
{
	players.erase(player);
}

void PlayerDB::findPlayer(string input)
{
	int matches = 0;
	for (int p = 0; p < allocatedElements; p++)
	{
		if (players[p].tag == input)
		{
			matches++;
			showPlayer(p);
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
	belPrint("There are ");
	belPrint(usedElements);
	belPrintLine("players.");
	for (int p = 0; p < allocatedElements; p++)
	{
		if (players[p].tag != "")
		{
			belPrint("Player ID - ");
			belPrintLine(p);
			players[p].print();
		}
	}
	
}

void PlayerDB::saveFile()
{
	save.openOut(filename);
	for (int i = 0; i < allocatedElements; i++)
	{
		save.belWriteLine("/");
		save.belWriteLine(players[i].sponsor);
		save.belWriteLine(players[i].tag);
		save.belWriteLine(players[i].playerMain);
		save.belWriteLine(players[i].wins);
		save.belWriteLine(players[i].losses);
	}
	save.close();
}

Player PlayerDB::player(int num)
{
	return players[num];
}

void PlayerDB::initArray(int initialSize)
{

}