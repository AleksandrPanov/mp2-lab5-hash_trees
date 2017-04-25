#include "word.h"

int Word::calculateHash(string & s)
{
	int t = 0;
	for (int i = 0; i < s.length(); i++)
		t += s[i];
	return t;
}
