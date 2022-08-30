#define _CRT_SECURE_NO_WARNINGS
#include "bank.h"
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

int bank::count = 0;

int check(int max)
{
	char vvod[15];
	gets_s(vvod);
	if (vvod[0] == NULL) gets_s(vvod);

	for (int i = 0; i < strlen(vvod); i++) {
		if ((vvod[i] < 48) || (vvod[i] > 57)) {
			cout << "Введите числовую информацию!" << endl;
			int out = check(max);
			return out;
		}
	}
	if ((atoi(vvod) > max) || (atoi(vvod) < 0))
	{
		cout << "Введенное число не попадает в заданный диапазон, проверьте корректность данных" << endl;
		int out = check(max);
		return out;
	}
	return atoi(vvod);
}

bank* operator+(bank& ob, int plus)
{
	ob.sum = ob.sum + plus;
	int a = 10, b;
	b = a << 2;
	return &ob;
}

void bank::operator<<(bank* ob)
{
	cout <<setw(15)<< ob->fio.fam << setw(15) << ob->fio.name << setw(15) << ob->fio.father << setw(15) <<
		ob->account << setw(15) << ob->sum << endl;
}

/*ostream& operator<<(ostream& p, list<bank>& ob)
{
	p << setw(15) << ob.get_fam() << setw(15) << ob.get_name() << setw(15) << ob.get_father() << setw(15) <<
		ob.account << setw(15) << ob.sum << endl;
	return p;
}*/

bank::bank( char* fam,  char* name,  char* father, int account, double sum)
{
	this->fio.fam = fam;
	this->fio.name = name;
	this->fio.father = father;
	this->account = account;
	this->sum = sum;
}

fio::fio()
{
	name = new char[100];
	strcpy(name, "");
	fam = new char[100];
	strcpy(fam, "");
	father = new char[100];
	strcpy(father, "");

}

fio::fio(char* f, char* n, char* o) 
{
	name = new char[100];
	strcpy(name, n);
	fam = new char[100];
	strcpy(fam, f);
	father = new char[100];
	strcpy(father, o);
}

fio::~fio()
{
	delete[] name;
	delete[] father;
	delete[] fam;
}

bank::bank()
{
	this->account = 123456;
	this->sum = 0;
}

bank::~bank()
{
	count--;
}

void bank::poisk(bank* s)   //поиск по номеру счета
{
	int flag;
	int akk;
	int x = 0;
	char buf1[150];
	cout<<"Введите номер счета: "<<endl;
	akk = check(10000000);
		bank* m = (bank*)malloc(count * sizeof(bank));
		for (int i = 0; i < count; i++)
		{
			if (s[i].account == akk)
			{
					m[x].fio.fam = s[i].fio.fam;
					m[x].fio.name = s[i].fio.name;
					m[x].fio.father = s[i].fio.father;
					m[x].account = s[i].account;
					m[x].sum = s[i].sum;
				x++;
			}
		}
			if (x > 0)
			{
				cout << "найдено " << x << " совпадений. Осуществить вывод искомых писем?(1-да, 0-нет)" << endl;
				flag = check(2);
				if ((flag == 1) && (x > 0))
				{
					cout << endl << endl;
					//printall(m, x);
					cout << endl;
				}
			}
			else cout << "Не найдено ни одного соответствия" << endl;
		free(m);
}

void bank::sort(bank* s)
{
	int t = 0;
	int flag;
	bank* d;
	d = (bank*)malloc(count * sizeof(bank));
		char buf[100];
		int tw;
		double tv;
		for (int j = 0; j < count; j++)
		{
			for (int i = 0; i < count - 1; i++)
			{
				if (s[i + 1].sum > s[i].sum)
				{
					strcpy(buf, s[i].fio.fam);
					s[i].fio.fam = (char*)realloc(s[i].fio.fam, sizeof(char) * (strlen(s[i + 1].fio.fam) + 1));
					strcpy(s[i].fio.fam, s[i + 1].fio.fam);
					s[i + 1].fio.fam = (char*)realloc(s[i + 1].fio.fam, sizeof(char) * (strlen(s[i].fio.fam) + 1));
					strcpy(s[i + 1].fio.fam, buf);

					strcpy(buf, s[i].fio.name);
					s[i].fio.name = (char*)realloc(s[i].fio.name, sizeof(char) * (strlen(s[i + 1].fio.name) + 1));
					strcpy(s[i].fio.name, s[i + 1].fio.name);
					s[i + 1].fio.name = (char*)realloc(s[i + 1].fio.name, sizeof(char) * (strlen(s[i].fio.name) + 1));
					strcpy(s[i + 1].fio.name, buf);

					strcpy(buf, s[i].fio.father);
					s[i].fio.father = (char*)realloc(s[i].fio.father, sizeof(char) * (strlen(s[i + 1].fio.father) + 1));
					strcpy(s[i].fio.father, s[i + 1].fio.father);
					s[i + 1].fio.father = (char*)realloc(s[i + 1].fio.father, sizeof(char) * (strlen(s[i].fio.father) + 1));
					strcpy(s[i + 1].fio.father, buf);

					tw = s[i].account;
					s[i].account = s[i + 1].account;
					s[i + 1].account = tw;

					tv = s[i].sum;
					s[i].sum = s[i + 1].sum;
					s[i + 1].sum = tv;
				}
			}

		}
		int l=2;
		cout << "Массив отсортирован, вывести его на экран?(1 - да, 0 - нет)" << endl;
	//	if (l==1) s->printall(s, count);
	free(d);
}

void bank::save_klient(bank* all, const char* filename)// сохранение данных на диске
{
	setlocale(0, "");
	FILE* file;
	file = fopen(filename, "w");
	if (file)
	{
		fprintf(file, "%d\n ", count);
		for (int i = 0; i < count; i++)
		{
			fprintf(file, "%15s ", all[i].fio.fam);
			fprintf(file, "%15s ", all[i].fio.name);
			fprintf(file, "%15s ", all[i].fio.father);
			fprintf(file, "%15d ", all[i].account);
			fprintf(file, "%15.0f\n ", all[i].sum);
		}
	}
	else
		cout << "Нет доступа к файлу!" << endl;
	//fclose(file);

}

void bank::printall( int n)
{
	cout << endl << "                  Таблица зарегистрированных клиентов:" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;;
	cout << "№" << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Отчество" << 
		setw(20) << "Номер счета" << setw(20) << "Сумма на счете" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; cout << endl, i++)
	{
		cout << i + 1 << " ";
		//cout << this[i];
	}
}

/*void bank::load_klient(bank*& p, const char* filename)
{
	FILE* fp;;
	char buf[100];
	int n;
	if ((fp = fopen(filename, "r")) == NULL)	printf("файл не открыт для чтения\n");
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s", buf);
		p[i].fio.fam = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(p[i].fio.fam, buf);
		fscanf(fp, "%s",buf);
		p[i].fio.name = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(p[i].fio.name, buf);
		fscanf(fp, "%s", buf);
		p[i].fio.father = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(p[i].fio.father, buf);
		fscanf(fp, "%s",buf);
		p[i].account = atoi(buf);
		fscanf(fp, "%s",buf);
		p[i].sum = atoi(buf);
	}
	count = n;
	fclose(fp);
}*/

void load_klient(list<bank>& mas, const char* filename)
{
	FILE* fp;
	char name[100];
	char fam[100];
	char fat[100];
	char buf[100];
	int s, a;
	int n;
	if ((fp = fopen(filename, "r")) == NULL)	printf("файл не открыт для чтения\n");
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s", fam);
		fscanf(fp, "%s", name);
		fscanf(fp, "%s", fat);
		fscanf(fp, "%s", buf);
		a = atoi(buf);
		fscanf(fp, "%s", buf);
		s = atoi(buf);
		mas.push_back(bank(fam, name, fat, a, s));
	}
	bank::count = n;
	fclose(fp);
}

void bank::add_klient(bank*& all)
{
	char buff[50];
	cout << "Ввод осуществляется латиницей!!!"<<endl;
	bank* mas = (bank*)malloc(sizeof(bank));
	cout<<"Фамилия: ";
	cin >> buff;
	all[count].fio.fam = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(all[count].fio.fam, buff);
	cout<<"Имя: ";
	cin >> buff;
	all[count].fio.name = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(all[count].fio.name, buff);
	cout<<"Отчество: ";
	cin >> buff;
	all[count].fio.father = (char*)malloc((strlen(buff) + 1) * sizeof(char*));
	strcpy(all[count].fio.father, buff);
	cout<<"Номер счета: ";
	all[count].account=check(10000000);
	cout<<"Сумма депозита ";
	all[count].sum=check(10000000);
}


