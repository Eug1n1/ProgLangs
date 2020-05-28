#pragma once

#include <stdarg.h>
#include <cfloat>

namespace Varparm {

	int ivarparm(int n, ...);

	short svarparm(short n, ...);

	float fvarparm(float n, ...);

	double dvarparm(double n, ...);

	float defaultparm(float a, float b, float c, float d, float e, float f = 5, float g = 7);

};
