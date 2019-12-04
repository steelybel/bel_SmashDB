#include <iostream>
#include "motown.h"
#include "player.h"

int main()
{
	PlayerDB data = PlayerDB();
	int crap = 1;
	while (crap == 1)
	{
		for (int p = 0; p < 200; p++)
		{
			data.showPlayer(p);
		}
		data.addPlayer();
	}
	return 0;
}