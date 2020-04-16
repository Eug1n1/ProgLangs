// LP_Lab08L.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"

#include <iostream>
#include "Dictionary.h"

using namespace Dictionary;

Instance Dictionary::Create(const char name[DICTNAMEMAXSIZE], int size)
{
	if (strlen(name) > DICTNAMEMAXSIZE)
		throw THROW01;

	if (size > DICTMAXSIZE)
		throw THROW02;
	Instance dict;
	strcpy_s(dict.name, name);
	dict.size = 0;
	dict.maxsize = size;

	dict.dictionary = new Entry[size];

	return dict;
}

void Dictionary::AddEntry(Instance& inst, Entry ed) {
	if (inst.size == inst.maxsize)
		throw THROW03;
	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == ed.id)
			throw THROW04;

	inst.dictionary[inst.size] = ed;

	inst.size++;
}

void Dictionary::DelEntry(Instance& inst, int id) {
	bool found = false;
	int elNum = 0;
	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == id)
			elNum = i;

	if (!elNum)
		throw THROW05;

	for (int i = elNum; i < inst.maxsize; i++)
		inst.dictionary[i] = inst.dictionary[i + 1];

	inst.size--;

}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) {
	int elNum = 0;

	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == id)
			elNum = i;

	if (!elNum)
		throw THROW07;

	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == new_ed.id)
			throw THROW08;

	inst.dictionary[elNum] = new_ed;
}

Entry Dictionary::GetEntry(Instance inst, int id) {
	int elNum = 0;

	for (int i = 0; i < inst.size; i++)
		if (inst.dictionary[i].id == id) {
			elNum = i;
		}


	if (elNum == 0)
		throw THROW05;

	return inst.dictionary[elNum];
}

void Dictionary::Print(Instance inst) {
	printf("--------- %s ---------\n", inst.name);
	for (int i = 0; i < inst.size; i++)
		printf("%d %s\n", inst.dictionary[i].id, inst.dictionary[i].name);
}

void Dictionary::Delete(Instance& d)
{
	d.maxsize = 0;
	d.size = 0;
}
