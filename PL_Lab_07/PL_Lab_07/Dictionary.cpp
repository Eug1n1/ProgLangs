#include <iostream>
#include "Dictionary.h"

using namespace Dictionary;

Instance Create(char* name, int size) {
	if (strlen(name) > DICTNAMEMAXSIZE)
		throw THROW01;
	
	if (size > DICTMAXSIZE)
		throw THROW02;
	Instance dict;
	strcpy_s(dict.name, name);
	dict.size = 0;
	dict.maxsize = size;

	return dict;
}

void AddEntry(Instance& inst, Entry ed) {
	if (inst.size == inst.maxsize)
		throw THROW03;
	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == ed.id)
			throw THROW04;

	inst.dictionary[inst.size] = ed;

	inst.size++;
}

void DelEntry(Instance& inst, int id) {
	bool found = false;
	int elNum = 0;
	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == id)
			elNum = i;

	if (!elNum)
		throw THROW05;

	for (int i = elNum; i < inst.size; i++)
		inst.dictionary[i] = inst.dictionary[i + 1];

	inst.size--;

}

void UpdEntry(Instance& inst, int id, Entry new_ed) {
	int elNum = 0;

	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id = id)
			elNum = i;

	if (!elNum)
		throw THROW07;

	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == new_ed.id)
			throw THROW08;

	inst.dictionary[elNum] = new_ed;
}

Entry GetEntry(Instance inst, int id) {
	int elNum = 0;

	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id = id)
			elNum = i;

	if (!elNum)
		throw THROW07;
	
	return inst.dictionary[elNum];
}

void Print(Instance inst) {
	printf("--------- %s ---------", inst.name);
	for (int i = 0; i < inst.size; i++)
		printf("%d %s\n", inst.dictionary[i].id, inst.dictionary[i].name);
}

void Delete(Instance* inst) {
	delete inst;
}