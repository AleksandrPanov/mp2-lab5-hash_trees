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
	int maxCollision = 0;

	int gHash(Key &k)
	{
		return Hash::getHash(k) % sizeTable;
	}
public:
	HashTableL(int size)
	{
		table = new List<Cont<Key, Data>>[size];
		sizeTable = size;
	}
	void insert(Key k, Data d)
	{
		Cont <Key, Data>tmp(k, d);
		Node<Cont<Key, Data>> *p;
		int h = gHash(k);
		p = table[h].find(tmp);
		if (p)
			table[h].update(p, tmp);
		else table[h].push_front(tmp);

		maxCollision = max(table[h].getSize() - 1, maxCollision);
	}
	void erase(Key k)
	{
		Data d = 0;
		Cont <Key, Data>tmp(k, d);
		int h = gHash(k);
		table[h].erase(tmp);
	}

	Data& operator [](Key k)
	{
		int h = gHash(k);
		Data t = 0;
		Cont <Key, Data> tmp(k, t);
		Node<Cont<Key, Data>> *p = table[h].find(tmp);
		if (p == 0)
		{
			table[h].push_front(tmp);
			p = table[h].find(tmp);
		}
		maxCollision = max(table[h].getSize() - 1, maxCollision);
		return p->data.gd();
	}

	int getMaxCol() { return  maxCollision; }

	void printTable()
	{
		for (int i = 0; i < sizeTable; i++)
		{
			while (table[i].size)
			{
				Cont<Key, Data> t = table[i].quick_pop_front();
				cout <<i<< ") hash = " <<Hash::getHash(t.k) <<" key = " << t.k << " data = "<<t.d<<'\n';
			}
		}
		cout << "max colision = " << maxCollision << '\n';
	}

	~HashTableL()
	{
		delete[] table;
	}
};
