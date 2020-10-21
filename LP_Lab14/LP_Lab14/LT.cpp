#include "LT.h"
#include "Error.h"

LT::LexTable LT::Create(int size)
{
	LexTable table;

	if (size < 0 || size > LT_MAXSIZE)
		throw Error::geterror(114);

	table.maxSize = size;
	table.size = 0;
	table.table = new Entry;

	return table;
}

void LT::Add(LexTable& lexTable, Entry entry)
{
	if (lexTable.size == lexTable.maxSize)
		throw ERROR_THROW(115);

	lexTable.table[lexTable.size] = entry;
	lexTable.size++;
}

LT::Entry LT::GetEntry(LexTable& lexTable, int n)
{
	if (n < 0 || n > lexTable.maxSize)
		throw ERROR_THROW(116);

	return lexTable.table[n];
}

void LT::Delete(LexTable& lexTable)
{
	delete &lexTable;
}
