#pragma once
#include "key.h"
class Container
{
protected:
	Key *key;
	Data *data;
public:
	Container(Key *k, Data *d);
	Data *getData() { return data; }
	Container operator = (const Container &c);
};