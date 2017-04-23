#pragma once
#include "list.h"

#define rep(i, n) for (int i = 0; i < (n); i++) 

inline int max(int a, int b)
{
	return (a > b ? a:b);
}
template <class Key, class Data> 
class Cont
{
public:
	Key k;
	Data d;
	
	Cont():k(),d(0){}
	Cont(Key &k1, Data &d1) : k(k1), d(d1) {};
	Cont (Key k1, Data d1, bool f) : k(k1), d(d1) {};

	Data& gd()
	{
		return d;
	}
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
	int maxCollisions = 0;
public:
	HashTableL(int size)
	{
		table = new List<Cont<Key, Data>>[size];
		sizeTable = size;
		Hash::sizeTable = sizeTable;
	}
	void insert(Key k, Data d)
	{
		Cont <Key, Data>tmp(k, d);
		Node<Cont<Key, Data>> *p;
		int h = Hash::getHash(k);
		p = table[h].find(tmp);
		if (p)
			table[h].update(p, tmp);
		else table[h].push_front(tmp);

		maxCollisions = max(table[h].getSize() - 1, maxCollisions);
	}
	void erase(Key k)
	{
		Data d = 0;
		Cont <Key, Data>tmp(k, d);
		int h = Hash::getHash(k);
		table[h].erase(tmp);
	}

	Data& operator [](Key k)
	{
		int h = Hash::getHash(k);
		Data t = 0;
		Cont <Key, Data> tmp(k, t);
		Node<Cont<Key, Data>> *p = table[h].find(tmp);
		if (p == 0)
		{
			insert(k, t);
			return table[h].find(tmp)->data.gd();
		}
		return p->data.gd();
	}

	int getMaxCol() { return  maxCollisions; }

	~HashTableL()
	{
		delete[] table;
	}
};
