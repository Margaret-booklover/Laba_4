#pragma once
#include <iostream>
#include <list>
class bank;
class fio
{
	 char* name;
	char* fam;
	char* father;
public:
	friend class bank;
	fio();
	~fio();
	friend bank* operator+(bank& ob, int plus);
	fio(char* f, char* n, char* o);
};

class bank
{
	fio fio;	
public:
	int account;
	double sum;
	static int count;
	bank();
	bank( char* fam,  char* name, char* father, int account, double sum);
	~bank();
	void save_klient(bank* all, const char* filename);
	void add_klient(bank*& all);
	void printall(int n);
	void sort(bank* s);
	void poisk(bank* s);
	char* get_fam() { return this->fio.fam; }
	char* get_name() { return this->fio.name; }
	char* get_father() { return this->fio.father; }
	void operator<<(bank* ob);
	friend bank* operator+(bank& ob, int plus);
};
