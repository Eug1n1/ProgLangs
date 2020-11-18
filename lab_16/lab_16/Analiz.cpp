#include "check.h"


#define EXP1 20
#define EXP2 73
#define EXP3 66

///êà ñ÷èò. âõ. ïîñë. ñèìâ.
FST::FST typeint("", 8,
	FST::NODE(1, FST::RELATION('i', 1)),
	FST::NODE(1, FST::RELATION('n', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('e', 4)),
	FST::NODE(1, FST::RELATION('g', 5)),
	FST::NODE(1, FST::RELATION('e', 6)),
	FST::NODE(1, FST::RELATION('r', 7)),
	FST::NODE()
);

FST::FST typestring("", 7,
	FST::NODE(1, FST::RELATION('s', 1)),
	FST::NODE(1, FST::RELATION('t', 2)),
	FST::NODE(1, FST::RELATION('r', 3)),
	FST::NODE(1, FST::RELATION('i', 4)),
	FST::NODE(1, FST::RELATION('n', 5)),
	FST::NODE(1, FST::RELATION('g', 6)),
	FST::NODE()
);

FST::FST typefunction("", 9,
	FST::NODE(1, FST::RELATION('f', 1)),
	FST::NODE(1, FST::RELATION('u', 2)),
	FST::NODE(1, FST::RELATION('n', 3)),
	FST::NODE(1, FST::RELATION('c', 4)),
	FST::NODE(1, FST::RELATION('t', 5)),
	FST::NODE(1, FST::RELATION('i', 6)),
	FST::NODE(1, FST::RELATION('o', 7)),
	FST::NODE(1, FST::RELATION('n', 8)),
	FST::NODE()
);

FST::FST strdeclare("", 8,
	FST::NODE(1, FST::RELATION('d', 1)),
	FST::NODE(1, FST::RELATION('e', 2)),
	FST::NODE(1, FST::RELATION('c', 3)),
	FST::NODE(1, FST::RELATION('l', 4)),
	FST::NODE(1, FST::RELATION('a', 5)),
	FST::NODE(1, FST::RELATION('r', 6)),
	FST::NODE(1, FST::RELATION('e', 7)),
	FST::NODE()
);

FST::FST streturn("", 7,
	FST::NODE(1, FST::RELATION('r', 1)),
	FST::NODE(1, FST::RELATION('e', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('u', 4)),
	FST::NODE(1, FST::RELATION('r', 5)),
	FST::NODE(1, FST::RELATION('n', 6)),
	FST::NODE()
);

FST::FST strmain("", 5,
	FST::NODE(1, FST::RELATION('m', 1)),
	FST::NODE(1, FST::RELATION('a', 2)),
	FST::NODE(1, FST::RELATION('i', 3)),
	FST::NODE(1, FST::RELATION('n', 4)),
	FST::NODE()
);

FST::FST strprint("", 6,
	FST::NODE(1, FST::RELATION('p', 1)),
	FST::NODE(1, FST::RELATION('r', 2)),
	FST::NODE(1, FST::RELATION('i', 3)),
	FST::NODE(1, FST::RELATION('n', 4)),
	FST::NODE(1, FST::RELATION('t', 5)),
	FST::NODE()
);

FST::FST expression("", 2,
	FST::NODE(4,
		FST::RELATION('+', 1),
		FST::RELATION('-', 1),
		FST::RELATION('*', 1),
		FST::RELATION('/', 1)),
	FST::NODE()
);
FST::FST probel("", 2,
	FST::NODE(1, FST::RELATION(' ', 1)),
	FST::NODE()
);
FST::FST leftbrace("", 2,
	FST::NODE(1, FST::RELATION('{', 1)),
	FST::NODE()
);
FST::FST rightbrace("", 2,
	FST::NODE(1, FST::RELATION('}', 1)),
	FST::NODE()
);
FST::FST leftthesis("", 2,
	FST::NODE(1, FST::RELATION('(', 1)),
	FST::NODE()
);
FST::FST rightthesis("", 2,
	FST::NODE(1, FST::RELATION(')', 1)),
	FST::NODE()
);
FST::FST semicolon("", 2,
	FST::NODE(1, FST::RELATION(';', 1)),
	FST::NODE()
);
FST::FST comma("", 2,
	FST::NODE(1, FST::RELATION(',', 1)),
	FST::NODE()
);
FST::FST plus("", 2,
	FST::NODE(1, FST::RELATION('+', 1)),
	FST::NODE());
FST::FST minus("", 2,
	FST::NODE(1, FST::RELATION('-', 1)),
	FST::NODE());
FST::FST del("", 2,
	FST::NODE(1, FST::RELATION('/', 1)),
	FST::NODE());
FST::FST umn("", 2,
	FST::NODE(1, FST::RELATION('*', 1)),
	FST::NODE());
FST::FST ravno("", 2,
	FST::NODE(1, FST::RELATION('=', 1)),
	FST::NODE());

FST::FST Literal("", 2,
	FST::NODE(20, FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
		FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
		FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
		FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
		FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
		FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
		FST::RELATION('8', 1), FST::RELATION('9', 1)),
	FST::NODE()
);

FST::FST fstidenf("", 2,
	FST::NODE(54, FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
		FST::RELATION('c', 1), FST::RELATION('c', 0), FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0),
		FST::RELATION('f', 1), FST::RELATION('f', 0), FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
		FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
		FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
		FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
		FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
		FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
		FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
	FST::NODE()
);
LT::LexTable lextab = LT::Create(LT_MAXSIZE - 1);
IT::IdTable idtab = IT::Create(TI_MAXSIZE - 1);
std::fstream file;


namespace Checkup
{
	void toPolish(int exp) {

		if (PolishNotation(exp, lextab, idtab))
			std::cout << exp << ": Польска нотация построена" << std::endl;
		else
			std::cout << exp << ": Польска нотация не построена" << std::endl;
	}

	bool PolishNotation( int lextable_pos, LT::LexTable& lextab, IT::IdTable& idtab	)
	{
		std::stack<char> steck;
		int n = 0;
		char f = ' ';
		bool flagfunction = false;
		char string[256] = "";
		char str[256] = "";
		int length = 0;
		int strlength = 0;

		for (int i = 0; i < lextab.size; i++)
		{
			std::cout << lextab.table[i].lexema << std::endl;
		}

		while (lextab.table[lextable_pos + n].lexema[0] != ';')
		{
			if (lextab.table[lextable_pos + n].lexema[0] == '(' ||
				lextab.table[lextable_pos + n].lexema[0] == ')' ||
				lextab.table[lextable_pos + n].lexema[0] == 'v' ||
				lextab.table[lextable_pos + n].lexema[0] == 'l' ||
				lextab.table[lextable_pos + n].lexema[0] == 'i' ||
				lextab.table[lextable_pos + n].lexema[0] == ',')
			{

				if (lextab.table[lextable_pos + n].lexema[0] == '(')
				{
					steck.push('(');
				}

				if (lextab.table[lextable_pos + n].lexema[0] == 'v')
				{
					if (steck.empty())
					{
						steck.push(idtab.table[lextab.table[lextable_pos + n].idxTI].lexes[0]);
					}
					else
					{
						if (steck.top() == '(')
						{
							steck.push(idtab.table[lextab.table[lextable_pos + n].idxTI].lexes[0]);
						}
						else
						{
							while (!steck.empty())
							{
								if (steck.top() != '(')			
								{
									str[strlength] = steck.top();	
									strlength++;
									steck.pop();

									if (idtab.table[lextab.table[lextable_pos + n].idxTI].lexes[0] == '+' ||	
										idtab.table[lextab.table[lextable_pos + n].idxTI].lexes[0] == '-')
									{
										string[length] = str[strlength - 1];	
										length++;
										str[strlength - 1] = ' ';			
										strlength--;
									}

									if (idtab.table[lextab.table[lextable_pos + n].idxTI].lexes[0] == '/' ||	
										idtab.table[lextab.table[lextable_pos + n].idxTI].lexes[0] == '*')
									{
										if (str[strlength - 1] == '/' || str[strlength - 1] == '*')
										{
											string[length] = str[strlength - 1];
											length++;
											str[strlength - 1] = ' ';
											strlength--;
										}
									}
								}
								else
									break;
							}

							for (int i = 0; i < strlength; i++)
							{
								steck.push(str[strlength - 1 - i]);
							}
							strcpy(str, "");
							strlength = 0;
							steck.push(idtab.table[lextab.table[lextable_pos + n].idxTI].lexes[0]);
						}
					}
				}

				if (lextab.table[lextable_pos + n].lexema[0] == 'i' ||	
					lextab.table[lextable_pos + n].lexema[0] == 'l')
				{
					if (idtab.table[lextab.table[lextable_pos + n].idxTI].idtype == 2)
					{
						steck.push('@');
						flagfunction = true;
					}
					else
					{
						for (int i = 0; i < strlen(idtab.table[lextab.table[lextable_pos + n].idxTI].id); i++)
						{
							string[length] = idtab.table[lextab.table[lextable_pos + n].idxTI].id[i];
							length++;
						}
					}
				}

				if (lextab.table[lextable_pos + n].lexema[0] == ')' && !flagfunction)	
				{
					do
					{
						f = steck.top();
						steck.pop();	
						if (f != '(')
						{
							string[length] = f;
							length++;
						}
					} while (f != '(');
				}

				if (lextab.table[lextable_pos + n].lexema[0] == ')' && flagfunction)
				{
					flagfunction = false;
					do
					{
						f = steck.top();
						steck.pop();
						if (f != '(')
						{
							string[length] = f;
							length++;
						}
					} while (f != '@');
				}
			}
			else
				return false;
			n++;
		}
		while (!steck.empty())
		{
			string[length] = steck.top();
			steck.pop();
			length++;
		}

		for (int i = 0; i < length; i++)
		{
			lextab.table[lextable_pos + i].lexema[0] = string[i];
		}
		for (int i = 0; i < (n - length); i++)
		{
			lextab.table[i + lextable_pos + length].lexema[0] = '\0';
		}

		std::cout << "стало" << std::endl;
		for (int i = 0; i < lextab.size; i++)
		{
			std::cout << lextab.table[i].lexema << std::endl;
		}

		return true;


	}






	bool check(char* m, FST::FST fst)
	{
		fst.string = m;
		return FST::execute(fst);
	}

	void fill(int line, char m)
	{
		LT::Entry entry;
		entry.sn = line;
		if (m != 'i')
		{
			entry.idxTI = LT_TI_NULLIDX;
		}
		else
		{
			entry.idxTI = idtab.size;
		}
		memset(entry.lexema, '\0', strlen(entry.lexema) - 1);
		entry.lexema[0] = m;
		LT::Add(lextab, entry);
	}

	void Leksika(Parm::PARM parm, In::IN in)
	{
		char word[255] = "";
		char word2[255] = "";
		bool flagfun2 = false;
		char ch;
		int m = 0;
		int line = 1;
		bool rc = false;		///ôëàã êëþ÷ ñëîâ, èäåíò ðàñïîçí
		bool id = false;
		bool povt_id = false;
		bool flag_s = false;
		bool flag_i = false;
		bool pflag = false;
		bool flag_lit = false;
		bool povt_lit = false;
		bool povt = false;
		char lit = '0';
		int n = 0;
		IT::Entry entr;
		bool funflag = false;
		short odin = 0;
		char fun[10] = "global";
		char fun2[10] = "global";


		for (int i = 0; i < in.size; i++)
		{
			ch = in.text[i];
			rc = false;
			if (ch == IN_CODE_ENDL)
			{
				line++;
				fill(line, '|');
				continue;
			}
			if (ch == '\'')
			{
				odin++;
				if (odin == 2)
					odin = 0;
			}
			if (odin == 1)
			{
				word[m] = ch;
				m++;
				continue;
			}


			if (ch != ' ' && ch != ';' && ch != '-' && ch != '+' && ch != '/' && ch != '*' && ch != '\''
				&& ch != ',' && ch != ')' && ch != '(' && ch != '}' && ch != '{' && ch != IN_CODE_ENDL && ch != '=')
			{
				word[m] = ch;
				m++;
				continue;
			}

			else
			{
				word[m] = '\0';
				m = 0;

				if (ch == IN_CODE_ENDL)
				{
					line++;
					continue;
				}
				rc = check(word, typestring);	
				if (rc)
				{
					fill(line, LEX_STRING);
					flag_s = true;
				}
				if (!rc)
				{
					rc = check(word, typeint);	
					if (rc)
					{
						flag_i = true;
						fill(line, LEX_INTEGER);
					}
				}

				if (!rc)
				{
					rc = check(word, typefunction);	
					if (rc)
						fill(line, LEX_FUNCTION);
				}
				if (!rc)
				{
					rc = check(word, strdeclare);	
					if (rc)
						fill(line, LEX_DECLARE);
				}
				if (!rc)
				{
					rc = check(word, streturn);
					if (rc)
						fill(line, LEX_RETURN);
				}
				if (!rc)
				{
					rc = check(word, strmain);
					if (rc)
					{
						fill(line, LEX_MAIN);
						strcpy(fun, "main");
				
					}

				}
				if (!rc)
				{
					rc = check(word, strprint);	
					if (rc)
						fill(line, LEX_PRINT);
				}

				
				if (word[0] == '\'')
				{
					fill(line, LEX_LITERAL);
					for (int i = 0; i < strlen(word); i++)
						word2[i] = word[i + 1];	
					word2[strlen(word)] = '\0';
					rc = true;					
					flag_lit = true;
					flag_s = true;
				}

				if (!rc)
				{
					rc = check(word, Literal);
					if (rc)
					{
						fill(line, LEX_LITERAL);/// l
						flag_lit = true;
						flag_i = true;
					}

				}
				if (flag_lit && rc)
				{
					entr.idxfirstLE = line;		
					entr.idtype = IT::L;
					strcpy(entr.fun, "");
					if (idtab.size > 0)
					{
						for (int u = 0; u < idtab.size && rc; u++)
						{
							if (idtab.table[u].idtype == 4)	
							{
								if (flag_i == true)
								{
									if (atoi(word) == idtab.table[u].value.vint)
									{
										lextab.table[lextab.size - 1].idxTI = u;
										rc = false;
										povt_lit = true;
										flag_lit = false;
										flag_i = false;
									}
								}
								if (flag_s == true)
								{
									if (strcmp(word2, idtab.table[u].value.vstr.str) == 0)
									{
										lextab.table[lextab.size].idxTI = u;
										rc = false;
										povt_lit = true;
										flag_lit = false;
										flag_s = false;
									}
								}
							}
						}
					}
					if (!povt_lit)
					{
						lit++;
						strcpy(entr.lexes, "$");
						entr.id[0] = 'L';
						entr.id[1] = lit;
						entr.id[2] = '\0';
						flag_lit = false;	

						if (flag_s)
						{
							entr.iddatatype = IT::STR;				
							strcpy(entr.value.vstr.str, word2);		
							entr.value.vstr.len = strlen(word2);	
							flag_s = false;							
						}
						if (flag_i)
						{
							entr.iddatatype = IT::INT;
							entr.value.vint = atoi(word);
							flag_i = false;
						}
						lextab.table[lextab.size - 1].idxTI = idtab.size;
						IT::Add(idtab, entr);
					}
					else
						povt_lit = false;
				}

		
				if ((ch == ' ' && word[0] == '\0'))
				{
					memset(word, '\0', strlen(word));
					continue;
				}

			
				if (word[0] == '\0')
					rc = true;

			
				if (!rc)
				{
					rc = check(word, fstidenf);	
					if (rc)
						id = true;
				}
		
				if (rc && id)
				{
					rc = false;
					id = false;
					fill(line, LEX_ID);
					lextab.table[lextab.size].idxTI = idtab.size;
					if (lextab.table[lextab.size - 2].lexema[0] != 'f')
					{
						if (strlen(word) < ID_MAXSIZE)
							strcpy(entr.id, word);
						else
						{
							for (int i = 0; i < 4; i++)
							{
								entr.id[i] = word[i];
							}
						}
						entr.idxfirstLE = line;	
						strcpy(entr.fun, fun);	
					}
					else
					{
						if (strcmp(word, "substr") == 0 || strcmp(word, "strlen") == 0)
						{
							strcpy(entr.fun, "External");
						}
						else
						{
							strcpy(entr.fun, fun);
						}
						strcpy(entr.functionname, word);
						strcpy(entr.id, "null");
						entr.idxfirstLE = line;
					}

					if (idtab.size > 0)
						for (int u = 0; u < idtab.size && !rc; u++)
						{
							if (strcmp(fun, idtab.table[u].fun) == 0 ||
								strcmp(idtab.table[u].fun, "global") == 0 ||
								strcmp(idtab.table[u].fun, "External") == 0)
							{
								if (strcmp(idtab.table[u].id, "null") == 0 &&
									strcmp(idtab.table[u].functionname, word) == 0)
								{
									lextab.table[lextab.size - 1].idxTI = u;

									if (idtab.table[u].iddatatype == IT::INT)
									{
										flag_s = false;
									}
									if (idtab.table[u].iddatatype == IT::STR)
									{
										flag_i = false;
									}
									rc = false;
									povt_id = true;
								}
								if (strcmp(entr.id, idtab.table[u].id) == 0 &&	
									strcmp(idtab.table[u].id, "null") != 0)
								{
									lextab.table[lextab.size - 1].idxTI = u;
									if (idtab.table[u].iddatatype == IT::INT)
									{
										flag_s = false;
									}
									if (idtab.table[u].iddatatype == IT::STR)
									{
										flag_i = false;
									}
									rc = false;
									povt_id = true;
								}
							}
						}
					if (!povt_id)
					{
						entr.idtype = IT::V;
						strcpy(entr.lexes, "$");
						if (lextab.table[lextab.size - 2].lexema[0] == 'f')
						{
							entr.idtype = IT::F;
						}
						if ((lextab.table[lextab.size - 3].lexema[0] == '(' && lextab.table[lextab.size - 4].lexema[0] != 'v') || pflag)
						{
							entr.idtype = IT::P;
							pflag = true;
						}

						if (flag_s)
						{
							entr.iddatatype = IT::STR;			
							strcpy(entr.value.vstr.str, "");	
							entr.value.vstr.len = 0;			
							flag_s = false;					
						}

						if (flag_i)
						{
							entr.iddatatype = IT::INT;
							entr.value.vint = 0;
							flag_i = false;
						}
						IT::Add(idtab, entr);
					}
					else
						povt_id = false;
					rc = false;
				}
			}

			if (ch == '+' || ch == '*' || ch == '-' || ch == '/' || ch == '=')
			{
				char word2[5];
				rc = false;
				word2[0] = ch;
				word2[1] = '\0';
				strcpy(entr.lexes, word2);
				strcpy(entr.id, "oper");
				strcpy(entr.fun, "lexes");

				rc = check(word2, umn);
				if (rc)
					fill(line, LEX_STAR);
				if (!rc)
				{
					rc = check(word2, ravno);
					if (rc)
						fill(line, LEX_R);
				}
				if (!rc)
				{
					rc = check(word2, minus);
					if (rc)
						fill(line, LEX_MINUS);
				}
				if (!rc)
				{
					rc = check(word2, plus);
					if (rc)
						fill(line, LEX_PLUS);
				}
				if (!rc)
				{
					rc = check(word2, del);
					if (rc)
						fill(line, LEX_DIRSLASH);
				}

				for (int u = 0; u < idtab.size && !povt; u++)
				{
					if (strcmp(entr.lexes, idtab.table[u].lexes) == 0)
					{
						lextab.table[lextab.size - 1].idxTI = u;
						povt = true;
					}
				}
				if (!povt)
				{
					IT::Add(idtab, entr);
					lextab.table[lextab.size - 1].idxTI = idtab.size - 1;
				}
				povt = false;
			}

			if (ch == LEX_SEMICOLON || ch == LEX_LEFTHESIS ||
				ch == LEX_RIGHTHESIS || ch == LEX_LEFTBRACE ||
				ch == LEX_BRACELET || ch == LEX_COMMA)
			{
				rc = false;
				memset(word, '\0', strlen(word));
				word[0] = in.text[i];
				word[1] = '\0';
				rc = check(word, semicolon);
				if (rc)
					fill(line, LEX_SEMICOLON);
				if (!rc)
				{
					rc = check(word, leftbrace);
					if (rc)
					{
						n = 1;
						fill(line, LEX_LEFTBRACE);
						while (n < idtab.size + 1 && strcmp(fun, "main") != 0)
						{
							if (idtab.table[idtab.size - n].idtype == 2)
							{
								funflag = true;
								break;
							}
							n++;
						}
						if (funflag)
						{
							strcpy(fun2, fun);
							strcpy(fun, idtab.table[idtab.size - n].functionname);
							funflag = false;
						}
					}
				}
				if (!rc)
				{
					rc = check(word, rightbrace);
					if (rc)
					{
						fill(line, LEX_BRACELET);
						strcpy(fun, fun2);
					}
				}
				if (!rc)
				{
					rc = check(word, comma);
					if (rc)
						fill(line, LEX_COMMA);
				}
				if (!rc)
				{
					rc = check(word, leftthesis);
					if (rc)
					{
						fill(line, LEX_LEFTHESIS);
						if (idtab.table[idtab.size - 1].idtype == 2 && strcmp(fun, "global") == 0)
						{
							strcpy(fun2, fun);
							strcpy(fun, idtab.table[idtab.size - 1].functionname);
							flagfun2 = true;
						}
					}
				}
				if (!rc)
				{
					rc = check(word, rightthesis);
					if (rc)
					{
						fill(line, LEX_RIGHTHESIS);
						pflag = false;
						if (flagfun2)
						{
							strcpy(fun, fun2);
							flagfun2 = false;
						}

					}
				}
			}
			memset(word, '\0', strlen(word));
		}

		toPolish(EXP1);
		toPolish(EXP2);
		toPolish(EXP3);

		/////POLISHNOTATION
		//if (PolishNotation(EXP1, lextab, idtab))
		//	std::cout << EXP1 << ": Польска нотация построена" << std::endl;
		//else 		std::cout << EXP1 << ": Польска нотация не построена" << std::endl;

		//if (PolishNotation(EXP2, lextab, idtab))
		//	std::cout << EXP2 << ": Ïîëüñêàÿ íîòàöèÿ ïîñòðîåíà" << std::endl;
		//else 		std::cout << EXP2 << ": Ïîëüñêàÿ íîòàöèÿ íå ïîñòðîåíà" << std::endl;

		//if (PolishNotation(EXP3, lextab, idtab))
		//	std::cout << EXP3 << ":  Ïîëüñêàÿ íîòàöèÿ ïîñòðîåíà" << std::endl;
		//else 		std::cout << EXP3 << ": Ïîëüñêàÿ íîòàöèÿ íå ïîñòðîåíà" << std::endl;



		std::fstream file;
		file.open(parm.log);
		if (file.fail())
		{
			throw ERROR_THROW(112);
		}
		file << lextab.table[0].sn << ' ';

		for (int i = 0; i < lextab.size; i++)
		{
			if (lextab.table[i].lexema[0] == '|')
			{
				file << '\n';
				if (i != (lextab.size - 1))
				{
					file << lextab.table[i].sn << ' ';
				}
				continue;
			}
			file << lextab.table[i].lexema;

		}
		file << std::setw(20) << "Имя" << std::setw(2);
		file << std::setw(15) << "Тип" << std::setw(2);
		file << std::setw(20) << "Тип id" << std::setw(2);
		file << std::setw(20) << "Строка" << std::setw(2);
		file << std::setw(20) << "Значение" << std::setw(2);
		file << std::setw(15) << "Длина" << std::setw(2);
		file << std::setw(18) << "Область" << std::setw(2) << '\n';
		for (int i = 0; i < idtab.size; i++)
		{
			if (strcmp(idtab.table[i].id, "null"))
				file << std::setw(20) << idtab.table[i].id << std::setw(2);
			else
				file << std::setw(20) << idtab.table[i].functionname << std::setw(2);
			if (idtab.table[i].iddatatype == IT::INT)
			{
				file << std::setw(20) << "integer" << std::setw(2);
			}
			if (idtab.table[i].iddatatype == IT::STR)
			{
				file << std::setw(20) << "string" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::F)
			{
				file << std::setw(20) << "Функция" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::P)
			{
				file << std::setw(20) << "Параметр" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::L)
			{
				file << std::setw(20) << "Литерал" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::V)
			{
				file << std::setw(20) << "Переменная" << std::setw(2);
			}
			file << std::setw(20) << idtab.table[i].idxfirstLE << std::setw(2);
			if (idtab.table[i].iddatatype == IT::INT)
			{
				file << std::setw(20) << idtab.table[i].value.vint << std::setw(2) << std::setw(20) << " " << std::setw(2);
			}
			else
			{
				file << std::setw(20) << idtab.table[i].value.vstr.str << std::setw(2);
				file << std::setw(20) << idtab.table[i].value.vstr.len << std::setw(2);

			}
			file << std::setw(20) << idtab.table[i].fun << std::setw(2) << '\n';
		}
		file.close();
	}
};