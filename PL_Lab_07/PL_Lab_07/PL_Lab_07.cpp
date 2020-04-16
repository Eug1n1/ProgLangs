#include <iostream>
#include "Dictionary.h"
#include "stdafx.h"
using namespace std;
using namespace Dictionary;

int main()
{
	setlocale(LC_ALL, "ru");

#ifdef TEST_CREATE_01
#define over
	try
	{
		Instance d7 = Create("Thghghfaaaaaaaytytytyuuiuiuuioooop", 20);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#ifdef TEST_CREATE_02
#if defined over
#error "слишком много"
#else
#define over
	try
	{
		Instance d8 = Create("Priver", 120);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#endif
#ifdef TEST_ADDENTRY_03
#if defined over
#error "слишком много"
#else
#define over
	try
	{
		Instance d9 = Create("Poka", 1);
		Entry t1 = { 1, "Name" }, t2 = { 2, "Surname" };
		AddEntry(d9, t1);
		AddEntry(d9, t2);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#endif
#ifdef TEST_ADDENTRY_04
#if defined over
#error "слишком много"
#else
#define over
	try
	{
		Instance d10 = Create("Test4", 3);
		Entry t1 = { 1, "Name" }, t2 = { 1, "Surname" };
		AddEntry(d10, t1);
		AddEntry(d10, t2);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#endif
#ifdef TEST_GETENTRY_05
#if defined over
#error "слишком много"
#else
#define over
	try
	{
		Instance d11 = Create("Test2", 5);
		GetEntry(d11, 1);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#endif
#ifdef TEST_GETENTRY_06
#if defined over
#error "слишком много"
#else
#define over
	try
	{
		Instance d12 = Create("Test3", 5);
		DelEntry(d12, 1);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#endif
#ifdef TEST_UPDENTRY_07
#if defined over
#error "слишком много"
#else
#define over
	try
	{
		Instance d13 = Create("Test5", 5);
		Entry s6 = { 21, "hello" };
		UpdEntry(d13, 1, s6);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#endif
#ifdef TEST_UPDENTRY_08
#if defined over
#error "слишком много"
#else
#define over
	try
	{
		Instance d14 = Create("Test5", 5);
		Entry t5 = { 1, "Name" };
		AddEntry(d14, t5);
		Entry s7 = { 1, "world" };
		UpdEntry(d14, 1, s7);
	}
	catch (const char* ex)
	{
		cout << ex;
	}
#endif
#endif
#ifdef TEST_DICTIONARY
#if defined over
#error "слишком много"
#else
#define over
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
#endif
#endif
}