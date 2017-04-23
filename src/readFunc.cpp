#include <string>

#include "readFunc.h"

#define stop 0 //конец строки/файла
#define let 1 //буква
#define sig 2 //знак препинания или цифра
#define del 3 //разделитель

using std::string;

inline int getSym(char c)
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return let;
	else if (c >= '!' && c <= '@')
		return sig;
	else if (c == '\0') // должен быть '\0'
		return stop;
	else return del;
}
int readWord(char *start, char *& end, string &s)
{
	int i = 0;
	int f = getSym(start[i]);

	while (f == del)
	{
		i++;
		f = getSym(start[i]);
	}

	if (f == stop)
		return stop;

	start += i;
	end = start;
	i = 0;
		
	if (f == sig)
	{
		end++;
		s = string(start, 1);
		return sig;
	}

	while (f == let)
	{
		i++;
		f = getSym(start[i]);
	}
	end += i;
	s = string(start, i);
	return let;
}
void readText()
{
	List <string> l;
	string tmp;
	getline(cin, tmp, '\n');
	char *st = &tmp[0], *end;
	while (readWord(st, end, tmp) > 0)
	{
		l.push_front(string(tmp));
		st = end;
	}
	//return l;
}