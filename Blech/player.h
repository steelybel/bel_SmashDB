// player.h - Player and PlayerDB classes
#pragma once
#include "motown.h"
#include <vector>

using namespace std;
using std::string;

// Describes stats of a player
struct Player
{
	public:
		//Empty initialization (used to delete players)
		Player();

		//Full initialization with stats
		Player(string _tag, string _sponsor, int _main, int _win, int _lose);

		//Stats
		string tag;
		string sponsor;
		int playerMain;
		int wins;
		int losses;
		float winRate();

		//Public functions
		void print();
		void print(int n);
		void edit();
		void set(string _tag, string _sponsor, int _main, int _win, int _lose);

	private:
		//Private functions
		void addWins(int win);
		void addLosses(int lose);
		void changeName(string n);
		void changeSponsor(string s);
};

class DynArray
{
public:
	DynArray();
	Player* data;
	int allocated;
	int used;
};

// Contains all players and resulting data
class PlayerDB
{
public:
	//Empty initialization
	PlayerDB();
	//Returns one player from the database
	Player player(int num);
	//Filename for saving data
	const char * filename;
	//Accepts user input; allows access to the private functions
	void textParser();
	void intro();
private:
	//An inline method of saving/loading data to a text file
	TextFile save;
	//Where the magic happens (Player storage dynamic array)
	std::vector<Player> players;
	//Memory allocation
	int allocatedElements;
	//Number of elements within the array of players
	int usedElements;
	//Initializing dynamic array
	void initArray(int initialSize);
	//Text parser functions
	void showPlayer(int num);
	void findPlayer(string input);
	void showPlayers();
	void addPlayer();
	void removePlayer(int player);
	void saveFile();
};

//Currently unused, ideally would be used to check user input for characters much more leniently.
enum characters
{
	MARIO,
	DONKEYKONG,
	LINK,
	SAMUS,
	YOSHI,
	KIRBY,
	FOX,
	PIKACHU,
	LUIGI,
	NESS,
	CFALCON,
	JIGGLYPUFF,
	PEACH,
	BOWSER,
	ICECLIMBERS,
	SHEIK,
	ZELDA,
	DRMARIO,
	PICHU,
	FALCO,
	MARTH,
	YOUNGLINK,
	GANONDORF,
	MEWTWO,
	ROY,
	MRGAMEANDWATCH,
	//ALTERNATE NAMES
	DK = 1,
	DONKEY = 1,
	PIKA = 7,
	FALCON = 10,
	CAPTAINFALCON = 10,
	PUFF = 11,
	JIGGLY = 11,
	KOOPA = 13,
	ICECLIMBER = 14,
	DOC = 17,
	GANON = 22,
	DORF = 22,
	DORIYA = 22,
	GAMEANDWATCH = 25,
	GAMENWATCH = 25,
	MRGAMENWATCH = 25,
	GANDW = 25,
	GNW = 25,
	MRGANDW = 25,
	MRGNW = 25
};
static char characters2[26][20]
{
	"Mario",
	"Donkey Kong",
	"Link",
	"Samus",
	"Yoshi",
	"Kirby",
	"Fox",
	"Pikachu",
	"Luigi",
	"Ness",
	"Captain Falcon",
	"Jigglypuff",
	"Peach",
	"Bowser",
	"Ice Climbers",
	"Sheik",
	"Zelda",
	"Dr. Mario",
	"Pichu",
	"Falco",
	"Marth",
	"Young Link",
	"Ganondorf",
	"Mewtwo",
	"Roy",
	"Mr. Game & Watch"
};
class Character
{
	
};
