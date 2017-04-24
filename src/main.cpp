#include "hash.h"
#include "word.h"
#include "readFunc.h"
#include <iostream>
using std::string;
int main()
{
	HashTableL<string, int, Word> h(7);
	List<string> l;
	readText(l);
	return 0;
}