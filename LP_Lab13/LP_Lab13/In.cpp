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

	int Symbol = 0;
	int position = 0;

	while (!fin.eof()) {
		Symbol = fin.get();
		if (table[Symbol] == IN::T) {
			in.text[in.size] = Symbol;
			in.size++;
			if (Symbol == '\n') {
				in.lines++;
				position = 0;
			}
		}
		else if (table[Symbol] == IN::F) {
			throw ERROR_THROW_IN(111, in.lines, position);
		}
		else if (table[Symbol] == IN::I) {
			in.ignor++;
		}
		else {
			in.text[in.size] = table[Symbol];
			in.size++;
		}
		position++;
	}
	in.text[in.size - 1] = '\0';

	std::string BufStr = "";
	for (int i = 0; i < in.size + 1; i++) {
		if (in.text[i] != IN_CODE_SP) {
			if (in.text[i] == IN_CODE_ENDL) {
				if (BufStr != "") {
					FST::recognize(BufStr.c_str(), &fout);
					BufStr = "";
				}
			}
			else {
				BufStr += in.text[i];
			}
		}
		else {
			if (BufStr != "") {
				FST::recognize(BufStr.c_str(), &fout);
				BufStr = "";
			}
		}
	}
	fin.close();
	return in;
}
