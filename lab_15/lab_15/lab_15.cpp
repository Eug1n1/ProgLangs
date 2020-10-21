#include "Headers.h"
#include <stack>

#define DEBUG

std::string operations = "+-/*";

bool operationsFinder(char ch)
{
	if (operations.find(ch) != std::string::npos)
	{
		return true;
	}

	return false;
}

int prior(char ch)
{
	if (ch == '(' || ch == ')')
		return 0;
	else if (ch == ',')
		return 1;
	else if (ch == '+' || ch == '-')
		return 2;
	else if (ch == '*' || ch == '/')
		return 3;
	else if (ch == '[' || ch == ']')
		return 0;
}

bool toPolish(std::string source)
{
	std::string result;
	std::stack<char> stack;
	int elemIndex = 1;
	bool isFunc = false;
	int elemCount = 0;
	char funcName;

	for (int i = 0; i < source.length(); i++)
	{
		switch (source[i])
		{
		case '*':
		case '/':
		case '-':
		case '+':
			if (stack.empty() || stack.top() == '(')
			{
				stack.push(source[i]);
			}

			else
			{
				int symbolPrior = prior(source[i]);
				while (!stack.empty() && stack.top() != '(' && symbolPrior <= prior(stack.top()))
				{
					/*if (stack.top() == '(')
						break;*/
					result += stack.top();
					stack.pop();
				}
				stack.push(source[i]);
			}
			break;
		case '(':
			stack.push(source[i]);
			break;
		case ')':
			while (!stack.empty() && stack.top() != '(')
			{
				char top = stack.top();
				result += stack.top();
				stack.pop();
			}

			if (!stack.empty())
				stack.pop();

			if (isFunc)
			{
				isFunc = !isFunc;
				result += '@';
				result += elemCount + '0';
				result += funcName;
			}
			break;
		case '[':
			stack.push(source[i]);
			break;

		case ']':
			while (!stack.empty() && stack.top() != '[')
			{
				bool flag = stack.empty();
				char top = stack.top();
				result += stack.top();
				stack.pop();
			}
			if (!stack.empty())
				stack.pop();

			result += '@';
			result += elemIndex + '0';

			elemIndex = 1;
			break;

		case ',':
			elemIndex++;

			while (!stack.empty() && (stack.top() != '(' && stack.top() != '['))
			{
				result += stack.top();
				stack.pop();
			}
			break;
		case 'i':
			if (isFunc)
			{
				elemCount++;
			}

			if (source[i + 1] == '(')
			{
				isFunc = !isFunc;
				elemCount = 0;
				funcName = source[i];
			}
			else
			{
				result += source[i];
			}
			
			break;
		}
	}
	while (!stack.empty())
	{
		result += stack.top();
		stack.pop();
	}
	std::cout << result << std::endl;
	return true;
}

bool polish(std::string source)
{

	std::string result;
	std::stack<char> stack;
	int elemIndex = 1;
	bool isFunc = false;
	int count = 0;
	char funcName;

	//for (int i = 0; i < source.length(); i++)
	//{
	//	if (source[i] == '(')
	//		bracketCheck++;
	//	else if (source[i] == ')')
	//		bracketCheck--;
	//}

	//if (bracketCheck)
	//{
	//	return false;
	//}

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
					while (!stack.empty() && stack.top() != '[')
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
			while (!stack.empty() && stack.top() != '(')
			{
				result += stack.top();
				stack.pop();
			}

			if (!stack.empty())
				stack.pop();

			if (isFunc)
			{
				isFunc = !isFunc;
				result += '@';
				result += count + '0';
				result += funcName;
			}
		}
		else if (source[i] == ',')
		{
			elemIndex++;

			while (!stack.empty() && (stack.top() != '(' && stack.top() != '['))
			{
				result += stack.top();
				stack.pop();
			}
		}
		else if (source[i] == '[')
		{
			stack.push(source[i]);
		}
		else if (source[i] == ']')
		{
			while (!stack.empty() && stack.top() != '[')
			{
				bool flag = stack.empty();
				char top = stack.top();
				result += stack.top();
				stack.pop();
			}
			stack.pop();

			result += '@';
			result += elemIndex + '0';

			elemIndex = 1;
		}
		else if (i + 1 <= source.length() && source[i] == 'i' && source[i + 1] == '(')
		{
			isFunc = !isFunc;
			count = 0;
			funcName = source[i];
		}
		else if (source[i] == 'i')
		{
			if (isFunc)
			{
				count++;
			}

			result += source[i];
		}
		else
		{
			return false;
		}
	}
	//i(i, i)
	//	ii@2i
	while (!stack.empty())
	{
		result += stack.top();
		stack.pop();
	}
#ifdef DEBUG
	std::cout << result << std::endl;
#endif

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");
	std::ifstream fin("C:\\projs\\1.txt");
	std::string source = "";
	while (!fin.eof())
	{
		std::getline(fin, source);
		if (toPolish(source))
		{
			std::cout << source << std::endl;
			std::cout << "разобрано\n" << std::endl;
		}
		else
		{
			std::cout << source << std::endl;
			std::cout << "не разобрано\n" << std::endl;
		}
	}
}