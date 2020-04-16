#include <iostream>
#include "../LP_Lab08L/Dictionary.h"

#pragma comment(lib, "D:\\cpp_projs\\PL\\LP_Lab08S\\Debug\\LP_Lab08L.lib ")

using std::cout;
using std::endl;
using namespace Dictionary;

int main()
{
	try {
		setlocale(LC_ALL, "ru");

		Instance d1 = Create("Преподаватели", 5);
		Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" }, e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 2, "Пацей" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		Entry ex2 = GetEntry(d1, 4);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "Гурин" };
		UpdEntry(d1, 3, newentry1);
		Print(d1);

		Instance d2 = Create("Студенты", 30);
		Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 4, "Николаев" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (char* e) {
		cout << e << endl;
	}
}
