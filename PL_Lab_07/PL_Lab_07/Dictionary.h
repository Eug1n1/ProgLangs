#pragma once

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной ёмкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден"
#define THROW06 "DelEntry: не найден"
#define THROW07 "UpdEntry: не найден"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary
{
    struct Entry {
        int id;
        char name[ENTRYNAMEMAXSIZE];
    };

    struct Instance {
        char name[DICTNAMEMAXSIZE];
        int maxsize;
        int size;
        Entry* dictionary;
    };


}