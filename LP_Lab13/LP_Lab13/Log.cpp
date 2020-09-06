#define _CRT_SECURE_NO_WARNINGS

#include "Log.h"

Log::LOG Log::getlog(wchar_t logfile[])
{
	Log::LOG tmp;
	tmp.stream = new std::ofstream;
	tmp.stream->open(logfile);
	if (!tmp.stream->is_open())
		throw ERROR_THROW(112);
	wcscpy_s(tmp.logfile, logfile);// копируем название нашего файла
	return tmp;
}

void Log::WriteLine(LOG log, char* c, ...)
{
	
	std::string str;
	va_list args;
	va_start(args, c);
	char* i = c;
	while (i != "")
	{
		str += i;
		i = va_arg(args, char*);
	}
	va_end(args);
	*log.stream << str << '\n';
	log.stream->flush();
	return;
}

void Log::WriteLine(LOG log, const wchar_t* c, ...)
{
	const wchar_t** ptr = &c;

	char temp[100];

	while (*ptr != L"")
	{
		wcstombs(temp, *ptr++, sizeof(temp));
		*log.stream << temp;
		++ptr;
	}
}

void Log::WriteLog(LOG log)
{
	*log.stream << "------ Протокол ------\n------ Дата: ";
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);
	char buf[228];
	strftime(buf, sizeof(buf), "%c", &date);
	*log.stream << buf << "------\n";
	return;
}

void Log::WriteParm(LOG log, Parm::PARM parm)//
{
	char str[255];

	*log.stream << "----- Параметры -----\n";

	wcstombs(str, parm.in, wcslen(parm.in));
	str[wcslen(parm.in)] = '\0';
	*log.stream << "-in: ";
	log.stream->write(str, strlen(str)) << "\n";

	wcstombs(str, parm.out, wcslen(parm.out));
	str[wcslen(parm.out)] = '\0';
	*log.stream << "-out: ";
	log.stream->write(str, strlen(str)) << "\n";

	wcstombs(str, parm.log, wcslen(parm.log));
	str[wcslen(parm.log)] = '\0';
	*log.stream << "-log: ";
	log.stream->write(str, strlen(str)) << "\n";
	log.stream->flush();
}

void Log::WriteIn(LOG log, In::IN in)
{
	*log.stream << "----- Исходные данные -----";
	*log.stream << "\nВсего символов : " << in.size;
	*log.stream << "\nПроигнорировано: " << in.ignor;
	*log.stream << "\nВсего строк    : " << in.lines;
	log.stream->flush();
	return;
}

void Log::WriteError(LOG log, Error::ERROR error)
{
	if (log.stream != NULL)
	{
		*log.stream << "Ошибка " << error.id << ": " << error.message << ", строка" << error.inext.line << " позиция " << error.inext.col;
		log.stream->flush();
		std::cout << "Ошибка " << error.id << ": " << error.message << ", строка" << error.inext.line << " позиция " << error.inext.col;
	}
	else
	{
		std::cout << "Ошибка " << error.id << ": " << error.message << ", строка" << error.inext.line << " позиция " << error.inext.col;
	}
	return;
}

void Log::Close(LOG log)
{
	log.stream->close();
	delete log.stream;
	return;
}


