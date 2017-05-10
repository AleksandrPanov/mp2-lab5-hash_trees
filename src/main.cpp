#include "hash.h"
#include "word.h"
#include "readFunc.h"
#include "binTree.h"
#include <iostream>
using std::string;
int main()
{
	HashTableL<string, int, Word> h(7);
	//read_text_in_table(h);
	//h.printTable();

	queue<int> q;
	

	BinTree<string, int> t;
	read_text_in_table(t);
	t.printBFS();
	return 0;
}