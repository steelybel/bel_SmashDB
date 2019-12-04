//motown.cpp
#include "motown.h"
#include <iostream>

void printNumbers(int nums[], size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << nums[i] << std::endl;
	}
}

void belPrint(char string[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		std::cout << string[i];
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
		std::cout << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
}

void belPrint(int num)
{
	std::cout << num;
}

void belPrintLine(char string[])
{
	for (int i = 0; i < strlen(string); i++)
	{
		std::cout << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
	std::cout << std::endl;
}

void belPrintLine(const char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		std::cout << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
	std::cout << std::endl;
}

void belPrintLine(int num)
{
	std::cout << num;
	std::cout << std::endl;
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
		std::cout << lower[i];
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
		std::cout << upper[i];
		if (upper[i] == '\0')
		{
			break;
		}
	}
	std::cout << std::endl;
}
