#include "Parm.h"

Parm::PARM Parm::getparm(int argc, _TCHAR* argv[]) {
    PARM p;
    wchar_t* inParm = nullptr, * outParm = nullptr, * logParm = nullptr;

    for (int i = 1; i < argc; i++)
    {
        if (wcslen(argv[i]) > PARM_MAX_SIZE)
        {
            throw ERROR_THROW(104);
        }
    }

	for (int i = 1; i < argc; i++)
	{
		inParm = wcsstr(argv[i], PARM_IN);
		if (inParm != nullptr)
		{
			break;
		}
	}
	if (inParm == nullptr)
	{
		throw ERROR_THROW(100);
	}

    for (int i = 1; i < argc; i++) 
	{
        inParm = wcsstr(argv[i], PARM_IN);
        if (inParm) 
		{
            wcscpy_s(p.in, inParm + wcslen(PARM_IN));
            break;
        }
    }

    for (int i = 1; i < argc; i++) 
	{
        outParm = wcsstr(argv[i], PARM_OUT);
        if (outParm) 
		{
            wcscpy_s(p.out, outParm + wcslen(PARM_OUT));
            break;
        }
    }
    if (!outParm) {
        wcscpy_s(p.out, inParm + wcslen(PARM_IN));
        wcscat_s(p.out, PARM_OUT_DEFAULT_EXT);
    }

    for (int i = 1; i < argc; i++) 
	{
        logParm = wcsstr(argv[i], PARM_LOG);
        if (logParm) 
		{
            wcscpy_s(p.log, logParm + wcslen(PARM_LOG));
            break;
        }
    }
    if (!logParm)
	{
        wcscpy_s(p.log, inParm + wcslen(PARM_IN));
        wcscat_s(p.log, PARM_LOG_DEFAULT_EXT);
    }

    return p;
}