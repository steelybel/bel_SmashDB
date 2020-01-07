//motown.h - Functions (rather, funk-tions, hence the filename) & some global classes.
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void printNumbers(int nums[], size_t size);
void setString(char string[], char set[]);
void ToLower(char string[]);
void ToUpper(char string[]);
void belPrint(char string[]);
void belPrint(const char* string);
void belPrint(std::string str);
void belPrint(int num);
void belPrint(float num);
void belPrintLine(char string[]);
void belPrintLine(const char* string);
void belPrintLine(std::string str);
void belPrintLine(int num);
void belPrintLine(float num);
void belIgnore();

class TextFile
{
public:
	TextFile();
	TextFile(const char * fn);
	void operator =(const char * fn);
	void openIn();
	void openOut();
	void openIn(const char * fn);
	void openOut(const char * fn);
	void close();
	void belWrite(char string[]);
	void belWrite(const char* string);
	void belWrite(std::string str);
	void belWrite(int num);
	void belWrite(float num);
	void belWriteLine(char string[]);
	void belWriteLine(const char* string);
	void belWriteLine(std::string str);
	void belWriteLine(int num);
	void belWriteLine(float num);
private:
	std::fstream file;
	const char * filename;
};