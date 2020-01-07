//motown.cpp
#include "motown.h"

using namespace std;
using std::string;

void printNumbers(int nums[], size_t size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << nums[i] << endl;
	}
}

void belPrint(char string[])
{
	for (unsigned int i = 0; i < strlen(string); i++)
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
	for (unsigned int i = 0; i < strlen(string); i++)
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
	for (unsigned int i = 0; i < strlen(string); i++)
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
	for (unsigned int i = 0; i < strlen(string); i++)
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
	for (unsigned int i = 0; i < strlen(string); i++)
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
	for (unsigned int l = 0; l < strlen(string); l++)
	{
		lower[l] = string[l];
		if (lower[l] > 64 && lower[l] < 91)
		{
			lower[l] += 32;
		}
	}
	for (unsigned int i = 0; i < strlen(lower); i++)
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
	for (unsigned int l = 0; l < strlen(string); l++)
	{
		upper[l] = string[l];
		if (upper[l] > 96 && upper[l] < 123)
		{
			upper[l] -= 32;
		}
	}
	for (unsigned int i = 0; i < strlen(upper); i++)
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

TextFile::TextFile()
{
	filename = "empty.txt";
}

TextFile::TextFile(const char * fn)
{
	filename = fn;
}

void TextFile::openIn()
{
	file.open(filename, std::ios::in);
}

void TextFile::openOut()
{
	file.open(filename, std::ios::out);
}

void TextFile::openIn(const char * fn)
{
	file.open(fn, std::ios::in);
}

void TextFile::openOut(const char * fn)
{
	file.open(fn, std::ios::out);
}

void TextFile::close()
{
	file.close();
}

void TextFile::operator = (const char * fn)
{
	filename = fn;
}

void TextFile::belWrite(char string[])
{
	if (file.is_open())
	{
		for (unsigned int i = 0; i < strlen(string); i++)
		{
			file << string[i];
			if (string[i] == '\0')
			{
				break;
			}
		}
	}
}

void TextFile::belWrite(const char* string)
{
	if (file.is_open())
	{
		for (unsigned int i = 0; i < strlen(string); i++)
		{
			file << string[i];
			if (string[i] == '\0')
			{
				break;
			}
		}
	}
}

void TextFile::belWrite(string str)
{
	if (file.is_open())
	{
		file << str;
	}
}

void TextFile::belWrite(int num)
{
	if (file.is_open())
	{
		file << num;
	}
}

void TextFile::belWrite(float num)
{
	if (file.is_open())
	{
		file << num;
	}
}

void TextFile::belWriteLine(char string[])
{
	for (unsigned int i = 0; i < strlen(string); i++)
	{
		file << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
	file << endl;
}

void TextFile::belWriteLine(const char* string)
{
	for (unsigned int i = 0; i < strlen(string); i++)
	{
		file << string[i];
		if (string[i] == '\0')
		{
			break;
		}
	}
	file << endl;
}

void TextFile::belWriteLine(string str)
{
	if (file.is_open())
	{
		file << str << std::endl;
	}
}

void TextFile::belWriteLine(int num)
{
	if (file.is_open())
	{
		file << num;
		file << endl;
	}
}

void TextFile::belWriteLine(float num)
{
	if (file.is_open())
	{
		file << num;
		file << endl;
	}
}