#include <iostream>

//ShumskiyEvgeniy2001
//ШумскийЕвгений2001
//Шумский2001Evgeniy

//53 68 75 6D 73 6B 69 79 45 76 67 65 6E 69 79 32 30 30 31
//D8 F3 EC F1 EA E8 E9 C5 E2 E3 E5 ED E8 E9 32 30 30 31
//D8 F3 EC F1 EA E8 E9 32 30 30 31 45 76 67 65 6E 69 79

//UTF-8
//53 68 75 6D 73 6B 69 79 45 76 67 65 6E 69 79 32 30 30 31
//D0 A8 D1 83 D0 BC D1 81 D0 BA D0 B8 D0 B9 D0 95 D0 B2 D0 B3 D0 B5 D0 BD D0 B8 D0 B9 32 30 30 31
//D0 A8 D1 83 D0 BC D1 81 D0 BA D0 B8 D0 B9 32 30 30 31 45 76 67 65 6E 69 79

//UTF-16
//00 53 00 68 00 75 00 6D 00 73 00 6B 00 69 00 79 00 45 00 76 00 67 00 65 00 6E 00 69 00 79 00 32 00 30 00 30 00 31
//04 28 04 43 04 3C 04 41 04 3A 04 38 04 39 04 15 04 32 04 33 04 35 04 3D 04 38 04 39 00 32 00 30 00 30 00 31
//04 28 04 43 04 3C 04 41 04 3A 04 38 04 39 00 32 00 30 00 30 00 31 00 45 00 76 00 67 00 65 00 6E 00 69 00 79

char lf[] = "ShumskiyEvgeniy2001";
char rf[] = "ШумскийЕвгений2001";
char lr[] = "Шумский2001Evgeniy";

wchar_t Llf[] = L"ShumskiyEvgeniy2001";
wchar_t Lrf[] = L"ШумскийЕвгений2001";
wchar_t Llr[] = L"Шумский2001Evgeniy";

char* UpperW1251(char* destination, char* source) {

    for (int i = 0; i < strlen(source); i++)
        if((source[i] > 96 && source[i] < 123) || (source[i] > 223 && source[i] < 256))
            destination[i] = source[i] - 32;

    return destination;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << 'S' - 's' << std::endl;
    std::cout << 'L' - 'l' << std::endl;
    std::cout << 'Б' - 'б' << std::endl;
    std::cout << 'Г' - 'г' << std::endl;
    std::cout << 'Э' - 'э' << std::endl;

    char source[] = "12345sdfghjlйцгшщз";
    char destination[] = "124567890123456789";
    
    for (int i = 0; i < strlen(UpperW1251(destination, source)); i++) {
        std::cout << destination[i];
    }

    return 0;
}

