#pragma once
#include <string>
using std::string;

class Word
{
	static int calculateHash(string &s);
public:
	int getHash(string &s) { return calculateHash(s);}
};