#include "FST.h"

FST::RELATION::RELATION(char c, short ns)
{
	symbol = c;
	nnode = ns;
};

FST::NODE::NODE()
{
	n_relation = 0;
	relations = new RELATION[n_relation];
	RELATION* relations = NULL;
};

FST::NODE::NODE(short n, RELATION rel, ...)
{
	n_relation = n;
	RELATION* p = &rel;
	relations = new RELATION[n];
	for (short i = 0; i < n; i++) relations[i] = p[i];
};

FST::FST::FST(char* s, short ns, NODE n, ...)
{
	string = s;
	nstates = ns;
	nodes = new NODE[ns];
	NODE* p = &n;
	for (int k = 0; k < ns; k++) nodes[k] = p[k];
	rstates = new short[nstates];
	memset(rstates, 0xff, sizeof(short) * nstates);
	rstates[0] = 0;
	position = 0;
};



bool FST::execute(FST& fst)
{
	short* rstates = new short[fst.nstates]; 
	memset(rstates, 0xff, sizeof(short) * fst.nstates);
	bool rc = true;
	for (short i = 0; i < strlen(fst.string) && rc; i++)
	{
		rc = symbolCheck(fst, rstates);
		fst.position++;
		if (!rc) {
			throw "df";
		}
	};
	delete[] rstates;
	return rc;
};


bool FST::symbolCheck(FST& fst, short*& rstates)
{
	bool rc = false;
	std::swap(rstates, fst.rstates);
	for (short i = 0; i < fst.nstates; i++)
	{
		if (rstates[i] == fst.position)
			for (short j = 0; j < fst.nodes[i].n_relation; j++)
			{
				if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
				{
					fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
					rc =  true;
				};
			}
	};
	return rc;
};

void FST::FSTTest(char* string)
{
	using namespace FST;
	// i(b)+((c+o+n)b+)*b*r;	
	FST fst(
		string,
		8,
		NODE(1, RELATION('i', 1)),
		NODE(4, RELATION('b', 2), RELATION('b', 1), RELATION('b', 4), RELATION('b', 5)),
		NODE(3, RELATION('c', 3), RELATION('o', 3), RELATION('n', 3)),
		NODE(3, RELATION('b', 4), RELATION('b', 3), RELATION('b', 5)),
		NODE(2, RELATION('b', 5), RELATION('b', 4)),
		NODE(1, RELATION('r', 6)),
		NODE(1, RELATION(';', 7)),
		NODE()
	);
	if (execute(fst))
		std::cout << "цепочка " << fst.string << " распознана" << std::endl;
	else
		std::cout << "цепочка " << fst.string << " не распознана" << std::endl;
};