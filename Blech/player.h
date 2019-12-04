// player.h
#pragma once

// Describes stats of a player
struct Player
{
	public:
		Player();
		Player(char _tag[], char _sponsor[], int _main, int _win, int _lose);
		const char * tag;
		const char * sponsor;
		int playerMain;
		int wins;
		int losses;
		float winRate();
		void print();
	private:

};

// Contains all players and resulting data
class PlayerDB
{
public:
	PlayerDB();
	Player player(int num);
	void showPlayer(int num);
	void addPlayer();
private:
	Player players[200];
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
