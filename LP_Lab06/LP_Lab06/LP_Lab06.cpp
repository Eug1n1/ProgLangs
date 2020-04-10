#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::ofstream;
using std::ifstream;

typedef unsigned char  day;
typedef unsigned char month;
typedef unsigned short year;



struct Date {
    day dd;
    month mm;
    year yyyy;

    bool operator ==(const Date date) {
        return dd == date.dd && mm == date.mm && yyyy == date.yyyy;
    }

    bool operator <(const Date date) {
        if (yyyy < date.yyyy)
            return 1;
        else if (yyyy > date.yyyy)
            return 0;
        else {
            if (mm < date.mm)
                return 1;
            else if (mm > date.mm)
                return 0;
            else {
                if (dd < date.dd)
                    return 1;
                else if (dd > date.dd)
                    return 0;
                else
                    return 0;
            }
        }
    }



    bool operator >(const Date date) {
        if (yyyy > date.yyyy)
            return 1;
        else if (yyyy < date.yyyy)
            return 0;
        else {
            if (mm > date.mm)
                return 1;
            else if (mm < date.mm)
                return 0;
            else {
                if (dd > date.dd)
                    return 1;
                else if (dd < date.dd)
                    return 0;
                else
                    return 0;
            }
        }
    }
};

struct Birthday {
    short dd;
    short mm;
    short yyyy;
    char name[100];

    bool SearchByDate(short d, short m, short y) {
        return dd == d && mm == m && yyyy == y;
    }

    bool SearchByName(char n[100]){
        return strcmp(name, n) == 0 ? 1 : 0;
    }

    void write() {
        ofstream fout("save.txt", ofstream::app);
        fout.write((char*)this, sizeof(Birthday));
        fout.close();
    }

};

ostream& operator<<(ostream& out, const Birthday& b) {
    out << b.name << ": " << b.dd << "." << b.mm << "." << b.yyyy;
    return out;
}

struct Birthday list[100];
int listLength = 0;

void read() {
    ifstream fin("save.txt");
    while (fin.read((char*)&list[listLength], sizeof(Birthday))) {
        listLength++;
    }
    fin.close();
}

void sTask(){
    int times;
    cin >> times;
    if (times == 1) {
        list[0] = { 10, 4, 2001, "Tapochkin Nikita" };
        list[1] = { 20, 1, 1999, "Ivanov Ivan" };
        listLength = 2;
    }
    else {
        read();
    }



    int day, month, year;
    cin >> day >> month >> year;
    for (int i = 0; i < 2; i++) {
        if (list[i].SearchByDate(day, month, year))
            cout << list[i] << endl;
    }

    char name[100];
    cin.ignore(1, '\n');
    gets_s(name);
    for (int i = 0; i < listLength; i++)
        if (list[i].SearchByName(name))
            cout << list[i];
    
    if(times == 1)
        for (int i = 0; i < listLength; i++) {
            list[i].write();
        }
}

int main()
{
    Date date1 = { 7,1,1980 };
    Date date2 = { 7, 2, 1993 };
    Date date3 = { 7,1, 1980 };

    if (date1 < date2) cout << "true" << endl;
    else cout << "false" << endl;

    if (date1 > date2) cout << "true" << endl;
    else cout << "false" << endl;

    if (date1 == date2) cout << "true" << endl;
    else cout << "false" << endl;

    if (date1 == date3) cout << "true" << endl;
    else cout << "false" << endl;

    sTask();

    return 0;
}
