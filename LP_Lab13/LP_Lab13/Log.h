#pragma once
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>
#include <tchar.h>
#include <iomanip>
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Parm.h"
namespace Log
{
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE]; // имя файла протокола
		std::ofstream* stream; //выходной поток протокола
	};

	static const LOG INITLOG = { L"", NULL }; // структура для начальной инициализации
	LOG getlog(wchar_t logfile[]); // сформировать структуру 
	void WriteLine(LOG log, char* c, ...); //вывести в протокол конкатенацию строк
	void WriteLine(LOG log, const wchar_t* c, ...); // тоже самое, что и выше, только с wchar_t
	void WriteLog(LOG log); //вывод в протокол заголовок
	void WriteParm(LOG log, Parm::PARM parm); // информация о входных параметрах 
	void WriteIn(LOG log, In::IN in); // инфа о входном потоке
	void WriteError(LOG log, Error::ERROR error);  // инфа об ошибке 
	void Close(LOG log); // закрыть протокол

}