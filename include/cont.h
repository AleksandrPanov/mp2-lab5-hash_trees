#pragma once
template <class Key, class Data>
class Cont
{
public:
	Key k;
	Data d;

	Cont() :k(), d(0) {}
	Cont(Key &k1, Data &d1) : k(k1), d(d1) {};
	Cont(Key k1, Data d1, bool f) : k(k1), d(d1) {};
	Cont(Key &k1) : k(k1), d(0) {};

	Data& gd()
	{
		return d;
	}
	bool operator == (const Cont &c)
	{
		return k == c.k;
	}
	bool operator < (const Cont &c)
	{
		return k < c.k;
	}
	bool operator > (const Cont &c)
	{
		return k > c.k;
	}
};