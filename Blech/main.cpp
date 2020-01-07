#include "motown.h"
#include "player.h"

int main()
{
	int crap = 1;
	int bag = 0;
	const char * saveFile = "playerdb.txt";
	PlayerDB data = PlayerDB();
	data.filename = saveFile;
	while (crap == 1)
	{
		data.textParser();
	}
	return 0;
}