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