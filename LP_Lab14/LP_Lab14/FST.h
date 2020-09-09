#include <iostream>
#include"Log.h"
#pragma once

namespace FST {
	struct RELATION
	{
		char symbol;// символ перехода
		short nnode; // номер смежной строки
		RELATION(
			char c = 0x00, 
			short ns = NULL
		);
	};

	struct NODE
	{
		short n_relation; // кол-во рёбер
		RELATION* relations; // сами рёбра
		NODE();
		NODE(
			short n,
			RELATION rel, ... 
		);
	};

	struct FST
	{
		const char* string; // цепочка
		short position; //позиция в цепочке
		short nstates; // кол-во состояний
		NODE* nodes; // граф перехода
		short* rstates; // возможные состояния
		FST(
			const char* s, // цепочка(строка завершающая 0х00
			short ns, // кол-во состояний автомата
			NODE n, ... // список состояний(граф перехода)
		);

	};

	bool execute( 
		FST& fst // недетермированный конечный автомат
	);
	void recognize(const char* string, std::ofstream* fout);
	bool SymbolCheck(FST& fst, short*& rstates); // разбор одного символа
}
