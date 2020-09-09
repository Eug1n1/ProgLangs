#include "In.h"
#include "Error.h"
#include"FST.h"
#include <iostream>
#include<fstream>
#include <sstream>

In::IN In::getin(wchar_t infile[], wchar_t outfile[])
{
	IN in;
	in.ignor = 0;
	in.lines = 0;
	in.size = 0;
	std::ifstream fin(infile, std::ios::ate);
	std::ofstream fout(outfile);
	int filesize = (int)fin.tellg();
	in.text = new unsigned char[filesize + 1];
	fin.seekg(std::ios::beg);
	
	int table[] = IN_CODE_TABLE;

	memcpy_s(in.code, sizeof(in.code), table, sizeof(table));
	if (!fin.is_open()) {
		throw ERROR_THROW(110);
	}

	int symbol = 0;
	int position = 0;
	bool ignore = false;
	bool spaceIgnore = false;
	std::string str = "()+-=*/,";

	while (!fin.eof())
	{
		symbol = fin.get();

		if (symbol == 39)
		{
			ignore = !ignore;
		}

		if (symbol == ' ' && in.text[in.size - 1] == ' ')
		{
			spaceIgnore = true;
		}
		else if (spaceIgnore == true && symbol != 32)
		{
			spaceIgnore = false;
		}
		
		if (str.find(symbol) != std::string::npos && in.text[in.size - 1] == ' ')
		{
			in.size--;
		}
		else if(symbol == ' ' && str.find(in.text[in.size - 1]) != std::string::npos)
		{
			spaceIgnore = true;
		}


		
		if ((table[symbol] == IN::T || ignore == true) && spaceIgnore != true) 
		{


			in.text[in.size] = symbol;
			in.size++;
			if (symbol == '\n') {
				in.lines++;
				position = 0;
			}
		}
		else if (spaceIgnore == true) {
			in.ignor++;
		}
		else if (table[symbol] == IN::F) 
		{
			throw ERROR_THROW_IN(111, in.lines, position);
		}
		else if (table[symbol] == IN::I) 
		{
			in.ignor++;
		}
		else 
		{
			in.text[in.size] = table[symbol];
			in.size++;
		}
		position++;
	}
	in.text[in.size - 1] = '\0';

	//std::string BufStr = "";
	//for (int i = 0; i < in.size + 1; i++) {
	//	if (in.text[i] != IN_CODE_SP) {
	//		if (in.text[i] == IN_CODE_ENDL) {
	//			if (BufStr != "") {
	//				FST::recognize(BufStr.c_str(), &fout);
	//				BufStr = "";
	//			}
	//		}
	//		else {
	//			BufStr += in.text[i];
	//		}
	//	}
	//	else {
	//		if (BufStr != "") {
	//			FST::recognize(BufStr.c_str(), &fout);
	//			BufStr = "";
	//		}
	//	}
	//}
	
	for (int i = 0; i < in.size; i++) {
		fout << in.text[i];
	}

	fout.close();
 	fin.close();
	return in;
}
