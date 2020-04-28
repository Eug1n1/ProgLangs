#pragma once

#include <stdarg.h>
#include <cfloat>

namespace Varparm {

	int ivarparm(int n, ...);

	short svarparm(short n, ...);

	float fvarparm(float n, ...);

	double dvarparm(double n, ...);

	int defaultparm(int a, int b, int c, int d = 5, int e = 7);

};
