#include <iostream>
#include <string>
#include "motown.h"
#include "player.h"

using namespace std;
using std::string;

int main()
{
	PlayerDB data = PlayerDB();
	int crap = 1;
	int bag = 0;
	string find = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
	belPrintLine("Melee-CircuitDB 1.0\nCopyright 2019 Bel Industries\nNo copyright intended");
	belPrintLine("");
	belPrintLine("Type 'help' for help!");
	while (crap == 1)
	{
		data.textParser();
	}
	return 0;
}