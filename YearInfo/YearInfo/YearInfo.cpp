#include <iostream>


void start();
void enterDate(char* chDate);
bool leapYearChecker(int year);
bool dateChecker(int day, int month, int year, bool leapYear);
int dayNumber(int day, int month, int year, bool leapYear);

void main() {
    while (1) {

        printf("\n\nDo you want to enter date?(y/n): ");
        char choice;
        std::cin >> choice;
        if (choice == 'n')
            exit(0);
        else if (choice != 'y') {
            printf("\n\nIncorrect enter!\n\n");
            continue;
        }

        int day = 0, month = 0, year = 0;
        char chDate[10];

        enterDate(chDate);

        day = (chDate[0] - '0') * 10 + (chDate[1] - '0');
        month = (chDate[3] - '0') * 10 + (chDate[4] - '0');
        year = (chDate[6] - '0') * 1000 + (chDate[7] - '0') * 100 + (chDate[8] - '0') * 10 + (chDate[9] - '0');

        if (!dateChecker) {
            printf("\nincorrect date! pleasy try again\n\n");
            continue;
        }

        printf("\n\n......DATE_REPORT......\n\n\tDate: %d.%d.%d\n\t", day, month, year);
        std::cout << "Leap year: ";
        if (leapYearChecker(year))
            printf("true\n\t");
        else
            printf("false\n\t");
        printf("Day number: %d\n\n.......................\n\n", dayNumber(day, month, year, leapYearChecker(year)));
    }
}

void enterDate(char* chDate) {
    using namespace std;
    printf("\nEnter date like this DD.MM.YYYY:\n\n\t");
    cin >> chDate;
}

bool leapYearChecker(int year) {
    bool leapYear;
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 == 0)
        return true;
    else
        return false;
}

bool dateChecker(int day, int month, int year, bool leapYear) {
    if (month > 12 || month < 0)
        return false;
    else if (day < 0)
        return false;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        return false;
    else if (month == 2 && leapYear == false && day > 28)
        return false;
    else if (month == 2 && leapYear == true && day > 29)
        return false;
    return true;
}

int dayNumber(int day, int month, int year, bool leapYear) {
    int number = day;
    for (int i = 1; i < month; i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11)
            number += 30;
        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            number += 31;
        else if (i == 2 && leapYear == false)
            number += 28;
        else if (i == 2 && leapYear == true)
            number += 29;
    }
    return number;
}