#include <iostream>

void hello() {
    std::cout << "Hello" << std::endl;
}

void By() {
    std::cout << "By" << std::endl;
}

int main()
{
    bool t = true, f = false;

    char a = 'A';
    wchar_t ch = 'А';
    
    //Cамое маленькое число типа short -32 768 
    //Самое большое число типа short 32 767
    short X = 24;  // 0b0000 0000 0001 1000 = 0x18
    short X1 = -24; // 0b1111 1111 1110 1000 = 0xffe8

    short b7 = 24; //0111 1111 1111 1111 = 0x7fff
    short b8 = -24; //1000 0000 0000 0000 = 0x8000

    short big = 0x8000;
    short small = 0xffffffffffff8000;

    // unsigned short - 16bit
    // Cамое маленькое число типа short 0
    // Самое большое число типа short 65 535
    unsigned short maxShortUnNumber = 0xffff; // 1111 1111 1111 1111 = 0xffff
    unsigned short minShortUnNumber = 0x0000; // 0000 0000 0000 0000 = 0x0000
    
    //int - 32bit
    // Самое маленькое число типа int -2 147 483 648 =  1000 0000 0000 0000 0000 0000 0000 0000‬
    // Самое большое число типа int 2 147 483 647 = 0111 1111 1111 1111 1111 1111 1111 1111
    int IntNumberp = 25; // 0b0000 0000 0000 0000 0000 0000 0001 1001 = 0x00000019
    int IntNumbern = -25; // 0b1111 1111 1111 1111 1111 1111 1110 0111 = 0xffffffe7  

    //unsigned int -32bit
    //minUIntNumber = 0
    //maxUINumber = 4 294 967 295
    unsigned int minUIntNumber = 0x00000000; // 0b0000 0000 0000 0000 0000 0000 0000 0000 = 0x00000000
    unsigned int maxUIntNumber = 0xffffffff; // 0b1111 1111 1111 1111 1111 1111 1111 1111 = 0xffffffff
    
    //long - 32bit
    // Самого маленькое число типа long  -2 147 483 648 
    // Самое большое число типа long 2 147 483 647 
    long LongNumberp = 26; // 0000 0000 0000 0000 0000 0000 0001 1010 = 0x0000001a
    long LongNumbern = -26; // 1111 1111 1111 1111 1111 1111 1110 0110 = 0xffffffe6

    long maxLongNumber = 0x7fffffff; // 0111 1111 1111 1111 1111 1111 1111 1111 = 0x7fffffff
    long minLongNumber = 0x80000000; // 1000 0000 0000 0000 0000 0000 0000 0000‬ = 0x80000000

    //unsigned long - 32bit
    //Самого маленькое число типа unsigned long 0
    //Самое большое число типа unsigned unsigned long 4 294 967 295
    unsigned long maxULongNumber = 0x00000000;//0000 0000 0000 0000 0000 0000 0000 0000 = 0x00000000
    unsigned long minULongNumber = 0xffffffff;// ‭1111 1111 1111 1111 1111 1111 1111 1111 = ‬0xffffffff

    //float - 32bit
    float FloatNumberp = 16.0;// 0001 0000 => 0001.0000 e=4  =>  127 + 4 = 131  0.1000 0011.00000000000000000000000 = 0x41800000
    float FloatNumbern = -16.0;// 1111 0000 => 1.1110000 e=7 => 127 + 7 = 134  1.1000 0110.11100000000000000000000 = 0xс37

    //17
    float Number1 = 20.225f;
    float Number2 = -20.225f;
    float value1 = Number1 / 0;
    float value2 = Number2 / 0;
    float value3 = sqrt(-7.0f);

    //18
    char ch = 'A';
    wchar_t wc = L'Т';
    short sh = 4;
    int i = 5;
    float fl = 1.5f;
    double doub = 8.5;

    char* pc = &ch;
    wchar_t* pwc = &wc;
    short* ps = &sh;
    float* pf = &fl;
    double* pd = &doub;

    pc += 3;
    pwc += 3;
    ps += 3;
    pf += 3;
    pd += 3;

    //19
    void (*message)();

    message = hello;
    message();

    message = By;
    message();



    //20
    char& chlin = ch;
    wchar_t& wclin = wc;

    short& shlin = sh;
    int& ilin = i;
    float& fllin = fl;
    double& doublin = doub;
}
