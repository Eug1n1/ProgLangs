#include <iostream>
#include "Dictionary.h"

int main()
{
    setlocale(LC_ALL, "rus");
    
    try {
        using namespace Dictionary;
        Instance d10 = Create("Преподаватели", 3);
        Entry t1 = { 1, "Name" }, t2 = { 1, "Surname" };
        AddEntry(d10, t1);
        AddEntry(d10, t2);
        AddEntry(d10, t2);
    }
    catch (char* e) {
        printf("%s", e);
    };

    return 0;
}
