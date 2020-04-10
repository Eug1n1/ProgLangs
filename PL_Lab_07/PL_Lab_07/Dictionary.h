#pragma once

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02 "Create: �������� ������ ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04 "AddEntry: ������������ ��������������"
#define THROW05 "GetEntry: �� ������"
#define THROW06 "DelEntry: �� ������"
#define THROW07 "UpdEntry: �� ������"
#define THROW08 "UpdEntry: ������������ ��������������"

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