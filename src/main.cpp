#include "hash.h"
#include "word.h"
#include "readFunc.h"
#include <iostream>
using std::string;
int main()
{
	HashTableL<string, int, Word> h(7);
	read_text_in_table(h);
	h.printTable();
	return 0;
}