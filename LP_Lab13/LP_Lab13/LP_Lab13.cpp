#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"
#include <iostream>
#include <tchar.h>
#include <cwchar>

using std::endl;

void separator(In::IN in) {
    char* buf = new char[256];
    int j = 0; //rbbbbbbbc;b;e;
    for (int i = 0; i < in.size + 1; i++) {
        if (in.text[i] == '|') {
            buf[j] = '\0';
            FST::FSTTest(buf);
            j = 0;
            i++;
        }
        if(in.text[i] != '\n')
            buf[j++] = in.text[i];
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "ru");

    Log::LOG log = Log::INITLOG;
    try
    {
        Parm::PARM parm = Parm::getParm(argc, argv);
        log = Log::getlog(parm.log);
        Log::WriteLine(log, (char*)"Тест:", (char*)"без ошибок", (char*)"");
        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getIn(parm.in);
        Log::WriteIn(log, in);
        Log::Close(log);

        separator(in);
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);
    };
    return 0;
}
