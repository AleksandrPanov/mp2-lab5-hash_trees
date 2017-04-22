#pragma once
#include "list.h"

template <class Key, class Data> 
class Cont
{
public:
	Key k;
	Data d;
	
	Cont(){}
	Cont(Key &k1, Data &d1) : k(k1), d(d1) {};

	bool operator == (const Cont &c)
	{
		return k == c.k;
	}
private:
};

template <class Key, class Data, class Hash>
class HashTableL
{
private:
	int sizeTable;
	List<Cont<Key, Data>> *table;
public:
	HashTableL(int size)
	{
		table = new List<Cont<Key, Data>>[size];
		sizeTable = size;
	}
	void push(Key k, Data d)
	{
		Cont <Key, Data>tmp(k, d);
		Node<Cont<Key, Data>> *p;
		Hash hh;
		int h = hh.getHash(k);
		p = table[h].find(tmp);
		if (p)
			table[h].update(p, tmp);
		else table[hh.getHash(k)].push_front(tmp);
	}

};
