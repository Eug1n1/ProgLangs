#include "Varparm.h"


int Varparm::ivarparm(int n, ...){
	int result = 1;
	va_list f;

	va_start(f, n);
	
	for (int i = 0; i < n; i++) {
		result *= va_arg(f, int);
	}
	va_end(f);

	return result;
}

short Varparm::svarparm(short n, ...) {
	short result = 1;
	va_list f;

	va_start(f, n);
	
	for (int i = 0; i < n; i++) {
		result *= va_arg(f, short);
	}
	va_end(f);

	return result;
}

float Varparm::fvarparm(float n, ...) {
	float result = n, temp;
	va_list f;

	va_start(f, n);
	while ((temp = va_arg(f, double)) != FLT_MAX) {
		result += temp;
	}
	va_end(f);

	return result;
}

double Varparm::dvarparm(double n, ...) {
	double result = n, temp;
	va_list f;

	va_start(f, n);
	while((temp = va_arg(f, double)) != DBL_MAX){
		result += temp;
	}
	va_end(f);

	return result;
}
