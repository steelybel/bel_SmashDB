// player.h
#pragma once
#include <string>
#include <fstream>

using namespace std;
using std::string;

// Describes stats of a player
struct Player
{
	public:
		Player();
		Player(string _tag, string _sponsor, int _main, int _win, int _lose);
		string tag;
		string sponsor;
		int playerMain;
		int wins;
		int losses;
		float winRate();
		void print();
		void print(int n);
		void edit();
		void set(string _tag, string _sponsor, int _main, int _win, int _lose);
	private:
		void addWins(int win);
		void addLosses(int lose);
		void changeName(string n);
		void changeSponsor(string s);
};

// Contains all players and resulting data
class PlayerDB
{
public:
	PlayerDB();
	Player player(int num);
	void textParser();
	void showPlayer(int num);
	void findPlayer(string input);
	void showPlayers();
	void addPlayer();
private:
	Player *players = new Player[200];
};

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
