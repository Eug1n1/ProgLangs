#include "IT.h"
#include "Error.h"

IT::IdTable IT::Create(int size)
{
	IdTable table;

	if (size < 0 || size > IT_MAXSIZE)
		throw ERROR_THROW(117);

	table.maxSize = size;
	table.size = 0;
	table.table = new Entry;

	return table;
}

void IT::Add(IdTable& idTable, Entry entry)
{
	if (idTable.size == idTable.maxSize)
		throw ERROR_THROW(118);

	idTable.table[idTable.size] = entry;
	idTable.size++;
}

IT::Entry IT::GetEntry(IdTable& idTable, int n)
{
	if (n < 0 || n > idTable.size)
		throw ERROR_THROW(119);

	return idTable.table[n];
}

int IT::IsId(IdTable& idTable, char id[ID_MAXSIZE])
{
	return 0;
}

void IT::Delete(IdTable& idTable)
{
	delete &idTable;
}
// TODO: поправить таблицу ошибок
