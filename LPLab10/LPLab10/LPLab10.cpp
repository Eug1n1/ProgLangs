﻿#include "Error.h"
#include "Parm.h"
//#include "Log.h"
//#include "In.h"
#include <iostream>
#include <tchar.h>

using std::endl;

#define testParm 0
#define testError 0
#define testIn 0
#define testLog 0

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "ru");

#if testError
    std::cout << "---- тест Error::getError ----" << endl << endl;
    try
    {
        throw ERROR_THROW(100);
    }
    catch(Error::ERROR e)
    {
        std::cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
    };

    std::cout << "---- тест Error::getErrorIn ----" << endl << endl;
    try 
    {
        throw ERROR_THROW_IN(111, 7, 7);
    }
    catch (Error::ERROR e)
    {
        std::cout << "Ошибка " << e.id << ": " << e.message
            << ", строка " << e.inext.line
            << ", позиция " << e.inext.col << endl << endl;
    }
#endif

#if testParm
    std::cout << "---- тест Parm::getparm ----" << endl << endl;
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        std::wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << endl << endl;
    }
    catch (Error::ERROR e)
    {
        std::cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
    };
#endif


#if testIn
    std::cout << "---- тест In::getin ----" << endl << endl;
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        In::IN in = In::getin(parm.in);
        std::cout << in.text << endl;
        std::cout << " Всего символов: " << in.size << endl;
        std::cout << " Всего строк: " << in.lines << endl;
        std::cout << " Пропущено: " << in.ignor << endl;
    }
    catch (Error::ERROR e)
    {
        std::cout << " Ошибка " << e.id << ": " << e.message << endl;
        std::cout << " строки " << e.inext.line << " позиция " << e.inext.col << endl << endl;

    };

#endif

#if testLog
    Log::LOG log = Log::INITLOG;
    try
    {
        Parm::PARM parm = Parm::getParm(argc, argv);
        log = Log::getLog(parm.log);
        Log::WriteLine(log, "Тест: ", "без ошибок", "");
        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getIn(parm.in);
        Log::WriteIn(log, in);
        Log::Close(log);
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);
    };

#endif

    Parm::getParm(argc, argv);

    return 0;
}
