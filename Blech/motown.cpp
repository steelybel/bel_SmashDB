//motown.cpp
#include "motown.h"
#include <iostream>
#include <string>

using namespace std;
using std::string;

void printNumbers(int nums[], size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << nums[i] << endl;
	}
}

void belPrint(char string[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		cout << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
}

void belPrint(const char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		cout << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
}

void belPrint(string str)
{
	cout << str;
}

void belPrint(int num)
{
	cout << num;
}

void belPrint(float num)
{
	cout << num;
}

void belPrintLine(char string[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		cout << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
	cout << endl;
}

void belPrintLine(const char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		cout << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
	cout << endl;
}

void belPrintLine(string str)
{
	std::cout << str << std::endl;
}

void belPrintLine(int num)
{
	cout << num;
	cout << endl;
}

void belPrintLine(float num)
{
	cout << num;
	cout << endl;
}


void setString(char string[], char set[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		if (set[i] != '\0')
		{
			string[i] = set[i];
		}
		else
		{
			break;
		}
	}
}

void ToLower(char string[])
{
	char lower[50]{};
	for (int l = 0; l < strlen(string); l++)
	{
		lower[l] = string[l];
		if (lower[l] > 64 && lower[l] < 91)
		{
			lower[l] += 32;
		}
	}
	for (int i = 0; i < strlen(lower); i++)
	{
		cout << lower[i];
		if (lower[i] == '\0')
		{
			break;
		}
	}
	std::cout << std::endl;
}

void ToUpper(char string[])
{
	char upper[50]{};
	for (int l = 0; l < strlen(string); l++)
	{
		upper[l] = string[l];
		if (upper[l] > 96 && upper[l] < 123)
		{
			upper[l] -= 32;
		}
	}
	for (int i = 0; i < strlen(upper); i++)
	{
		cout << upper[i];
		if (upper[i] == '\0')
		{
			break;
		}
	}
	cout << std::endl;
}
void belIgnore() { std::cin.ignore(INT_MAX, '\n'); };