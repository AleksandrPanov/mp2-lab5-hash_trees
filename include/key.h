#pragma once
#include "data.h"
class Key
{
public:
	static void setSizeTable(int size) { sizeTable = size; }
protected:
	static int sizeTable;

	virtual void* getpKey() = 0;
public:
	virtual int getHash() = 0;
	virtual void setKey(Data *data) = 0;
};