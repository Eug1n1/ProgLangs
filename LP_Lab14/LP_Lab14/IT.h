#pragma once
#define ID_MAXSIZE		5
#define IT_MAXSIZE		4096
#define IT_INT_DEFAULT	0x00000000
#define IT_STR_DEFAULT	0x00
#define IT_NULLIDX		0xffffffff
#define IT_STR_MAXSIZE	255

namespace IT 
{
	enum IDDATATYPE { INT = 1, STR = 2 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 3 };

	struct Entry
	{
		int idxFirstLE;
		char id[ID_MAXSIZE];
		IDDATATYPE idDataType;
		IDTYPE idType;

		union 
		{
			int vInt;
			struct
			{
				char len;
				char str[IT_STR_MAXSIZE - 1];
			} vStr[IT_STR_MAXSIZE];
		} value;
	};

	struct IdTable
	{
		int maxSize;
		int size;
		Entry* table;
	};

	IdTable Create(int size);

	void Add(IdTable& idTable, Entry entry);

	Entry GetEntry(IdTable& idTable, int n);

	int IsId(IdTable& idTable, char id[ID_MAXSIZE]);

	void Delete(IdTable& idTable);
}

