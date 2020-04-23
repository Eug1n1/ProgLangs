#include <iostream>
#include "Varparm.h"
#include "Call.h"

using namespace Varparm;

int main()
{

    std::cout << "IVARPARM" << std::endl;
    std::cout << ivarparm(1, 4) << std::endl;
    std::cout << ivarparm(2, 5, 8) << std::endl;
    std::cout << ivarparm(3, 1, 2, 3) << std::endl;
    std::cout << ivarparm(7, 1, 2, 3, 4, 5, 6, 7) << std::endl << std::endl;


    std::cout << "SVARPARM" << std::endl;
    std::cout << svarparm(1, 1) << std::endl;
    std::cout << svarparm(2, 4, 5) << std::endl;
    std::cout << svarparm(3, 3, 4, 5) << std::endl;
    std::cout << svarparm(7, 1, 2, 3, 4, 5, 5, 7) << std::endl << std::endl;


    std::cout << "FVARPARM" << std::endl;
    std::cout << fvarparm(1.0, FLT_MAX) << std::endl;
    std::cout << fvarparm(2.0, 1.2, FLT_MAX) << std::endl;
    std::cout << fvarparm(3.0, 1.2, 2.8, FLT_MAX) << std::endl;
    std::cout << fvarparm(7.0, 1.2, 2.8, 3.6, 4.5, 5.5, 6.8, FLT_MAX) << std::endl << std::endl;


    std::cout << "DVARPARM" << std::endl;
    std::cout << dvarparm(1.0, DBL_MAX) << std::endl;
    std::cout << dvarparm(2.0, 4.5634, DBL_MAX) << std::endl;
    std::cout << dvarparm(3.0, 3.123, 4.5634, DBL_MAX) << std::endl;
    std::cout << dvarparm(7.0, 1.222, 2.666, 3.123, 4.5634, 5.8, 6.4, DBL_MAX) << std::endl << std::endl;


    int a = 1, b = 2, c = 3;
    std::cout << "CDEVL" << std::endl;
    std::cout << Call::cdevl(a, b, c) << std::endl << std::endl;

    std::cout << "CSTD" << std::endl;
    std::cout << Call::cstd(a, b, c) << std::endl << std::endl;

    std::cout << "CFST" << std::endl;
    std::cout << Call::cfst(1, 2, 3) << std::endl << std::endl;
}
