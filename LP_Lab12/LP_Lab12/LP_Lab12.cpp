#include "FST.h"

//r(b)*((с;b+);)+b*e;

int main()
{
    try {
        setlocale(LC_ALL, "ru");

        char myString1[] = "ibcbbr";
        FST::FSTTest(myString1);

        char myString2[] = "ibr;";
        FST::FSTTest(myString2);

        char myString3[] = "ibcbr;";
        FST::FSTTest(myString3);

        char myString4[] = "ibcbr;";
        FST::FSTTest(myString4);

        char myString5[] = "ibbcbbr;";
        FST::FSTTest(myString5);

        char myString6[] = "ibcbbbbr;";
        FST::FSTTest(myString6);

        char myString7[] = "ibcbbr;";
        FST::FSTTest(myString7);

        std::cout << "------------------ERROR--------------------" << std::endl;
        // i(b) + ((c + o + n)b + ) * b * r;
        char myString8[] = "ibbb;";
        FST::FSTTest(myString8);

        char myString9[] = "icbbr";
        FST::FSTTest(myString9);
    }
    catch (char* e) {
        std::cout << e << std::endl;
    }

    return 0;
}
