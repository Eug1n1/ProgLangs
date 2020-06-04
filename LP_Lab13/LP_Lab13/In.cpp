
#include "In.h"
#include "Error.h"
#include <locale.h>
#include <string>
#include <cwchar>

In::IN In::getIn(wchar_t infile[]) {

	std::ifstream stream(infile);

	int col = 0;
	IN in;
	in.size = 0;
	in.lines = 0;
	in.ignor = 0;
	int table[] = IN_CODE_TABLE;
	in.text = new unsigned char[IN_MAXLEN_TEXT];
	
	char ch;
	unsigned char cha;
	if (stream.is_open()) {
		while (!stream.eof()) {
			stream.get(ch);
			cha = ch;
			if (table[cha] == IN::T) {
				in.text[in.size] = cha;
				in.size++;
				if (cha == '\n') {
					in.lines++;
					col = 0;
				}
			}
			else if (table[cha] == IN::F) {
				throw ERROR_THROW_IN(111, in.lines, col);
			}
			else if (table[cha] == IN::I) {
				in.ignor++;
			}
			else {
				in.text[in.size] = table[cha];
				in.size++;
			}
			col++;
		}
		in.text[in.size - 1] = '\0';
	}
	else {
		throw ERROR_THROW(110);
	}

	stream.close();
	return in;
}