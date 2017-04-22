#pragma once
class Data
{
public:
	static void setSizeTable(int size) { sizeTable = size; }
protected:
	static int sizeTable;
	virtual int getHash() = 0;
	virtual void* getpKey() = 0;
	virtual void* getpData() = 0;
	//virtual void setpData(void *p) = 0;
};