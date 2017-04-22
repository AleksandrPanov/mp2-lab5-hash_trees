#include "hash.h"
#include "word.h"
#include <iostream>
using std::string;
int main()
{
	HashTableL<string, int, Word> h(7);
	h.push("ab",0);
	return 0;
}