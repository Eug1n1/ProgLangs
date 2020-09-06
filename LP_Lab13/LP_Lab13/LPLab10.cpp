#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>
#include <tchar.h>

#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	cout << "<--------------- Тест Error::geterror -------------->\n\n"; 
	try
	{
		throw ERROR_THROW(100);
	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
	}

	cout << "<--------------- Тест Error::geterrorin -------------->\n\n";
	try
	{
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message
			<< ",строка " << e.inext.line
			<< ",позиция " << e.inext.col << endl << endl;
	}

	cout << "<--------------- Тест Error::getparm -------------->\n\n";
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", log:" << parm.log << endl << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
	}

	cout << "<--------------- Тест Error::getin -------------->\n\n";
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "Всего символов: " << in.size << endl;
		cout << "Всего строк: " << in.lines << endl;
		cout << "Пропущено: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
	}

	cout << "<--------------- Тест Error::getin -------------->\n\n";
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "Всего символов: " << in.size << endl;
		cout << "Всего строк: " << in.lines << endl;
		cout << "Пропущено: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
		cout << ",строка " << e.inext.line
			<< ",позиция " << e.inext.col << endl << endl;
	}

	cout << "<--------------- Тест Log -------------->\n\n";
	Log::LOG log = Log::INITLOG;
	try
	{
		
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест:", (char*)"без ошибок", (char*)"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	return 0;
}