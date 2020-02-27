#include "stdafx.h"
#include <iostream>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

int main()
{
    std::cout << "sum(2, 3) = " << sum(2, 3) << std::endl;
    std::cout << "sub(2, 3) = " << sub(2, 3) << std::endl;
    std::cout << "mul(2, 3) = " << mul(2, 3) << std::endl;
    getchar();
}
