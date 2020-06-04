#include "FST.h"

//r(b)*((с;b+);)+b*e;

int main()
{
    setlocale(LC_ALL, "ru");

    char myString1[] = "rbc;b;be;";
    FST::FSTTest(myString1);

    char myString2[] = "rc;b;e;";
    FST::FSTTest(myString2);

    char myString3[] = "rbc;b;e;";
    FST::FSTTest(myString3);

    char myString4[] = "rc;b;be;";
    FST::FSTTest(myString4);

    char myString5[] = "rbbc;b;bbbe;";
    FST::FSTTest(myString5);

    char myString6[] = "rbc;b;bbbbbe;";
    FST::FSTTest(myString6);

    char myString7[] = "rbbbbbbbc;b;e;";
    FST::FSTTest(myString7);

    std::cout << "------------------ERROR--------------------" << std::endl;

    char myString8[] = "rbbbbbbb;b;e;";
    FST::FSTTest(myString8);

    char myString9[] = "rcb;e;";
    FST::FSTTest(myString9);

    return 0;
}
