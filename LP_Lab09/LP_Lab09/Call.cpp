#include "Call.h"

int _cdecl Call::cdevl(int& a, int& b, int& c)
{
	return a * b * c;
}

int _stdcall Call::cstd(int& a, int b, int c)
{
	return a * b * c;
}

int _fastcall Call::cfst(int a, int b, int c)
{
	return a * b * c;
}
