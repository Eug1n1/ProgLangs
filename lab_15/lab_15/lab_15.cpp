#include "Headers.h"
#include <stack>

std::string operations = "+-/*";

bool operationsFinder(char ch)
{
	if (operations.find(ch) != std::string::npos)
	{
		return true;
	}

	return false;
}

void polish(std::string source)
{
	
	std::string result;
	std::stack<char> stack;

	for (int i = 0; i < source.length(); i++)
	{
		if (operationsFinder(source[i]))
		{
			if (stack.empty() || stack.top() == '(')
			{
				stack.push(source[i]);
			}
			else
			{
				if (source[i] == '+' || source[i] == '-')
				{
					while (!stack.empty())
					{
						if (stack.top() == '(')
							break;
						result += stack.top();
						stack.pop();
					}
					stack.push(source[i]);
				}
				else
				{
					while (!stack.empty())
					{
						if (stack.top() != '/' || stack.top() != '*')
							break;
						result += stack.top();
						stack.pop();
					}
					stack.push(source[i]);
				}
			}
		}
		else if (source[i] == '(')
		{
			stack.push(source[i]);
		}
		else if (source[i] == ')')
		{
			while (stack.top() != '(')
			{
				result += stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else
		{
			result += source[i];
		}
	}


	while (!stack.empty())
	{
		result += stack.top();
		stack.pop();
	}

	std::cout << result << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	Log::LOG log = Log::INITLOG;
	Parm::PARM parm = Parm::getparm(argc, argv);
	log = Log::getlog(parm.log);

	In::IN in = In::getin(parm.in);
	//-----------------------
	Log::WriteLog(log);
	Log::WriteParm(log, parm);
	Log::WriteIn(log, in);

	try
	{

		Checkup::Leksika(parm, in);

	}
	catch (Error::ERROR e)
	{
		WriteError(log, e);
	};
	system("pause");
	return 0;
}