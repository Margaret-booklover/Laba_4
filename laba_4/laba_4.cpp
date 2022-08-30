#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "bank.h"
#include <list>
using namespace std;
int check(int max);
int main() {
	setlocale(LC_ALL, "rus");
	const int size_max = 200;
	const char* filename = "basa.txt";
	cout << "hello!" << endl;
	list<bank> mas;
	list<bank> ::iterator tv1 = mas.begin();
	FILE* fp;
	char name[100], fam[100], fat[100], buf[100];
	int s, a, n;
	if ((fp = fopen(name, "r")) == NULL)	printf("файл не открыт для чтения\n");
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
		bank p(fam, name, fat, a, s);
	//	mas.push_back(p);
	}
	bank::count = n;
	fclose(fp);
	//for (tv1 = mas.begin(); tv1 != mas.end(); ++tv1) // печать списка
	//	cout << *tv1 ;

	//tv1->printall(bank::count);
/*	bank s1;
	bank* all = (bank*)malloc(size_max * sizeof(bank));
	
	all->load_klient(all, name);
	int n, p, i;
	n = 0;
	do
	{
		cout << " На данный момент в системе зарегистрировано " << bank::count << " клиентов" << endl;
		cout << "---------------Меню-----------\n 1 - добавить нового клиента" << endl;
		cout << " 2- распечатать информацию о всех клиентах" << endl;;
		cout << " 3 - найти клиента по номеру счета" << endl << " 4 -сортировать по уменьшению суммы на счете" << endl;
		cout << " 5 - начислить/списать сумму" << endl << " 6 - завершить работу" << endl;
		cout << "---------------------------------" << endl << "Введите номер меню..." << endl;
		p = check(6);
		switch (p)
		{
		case 1:
		{   if (bank::count > size_max) cout << "количество клиентов в базе достигло максимума, невозможно добавить запись" << endl;
		else {
			all->add_klient(all);
			bank::count++;
			cout << "Регистрация прошла успешно" << endl;
		}
		break;
		}
		case 2:
		{
		all->printall(all, bank::count);
		break;
		}
		case 3:
		{
			all->poisk(all);
			break;
		}
		case 4:
		{
			all->sort(all);
			break;
		}
		case 5:
		{
			int plus;
			cout << "Введите сумму: ";
			plus = check(10000000);
			int k;
			cout << "Для зачисления суммы нажмите 1, для списания - 0" << endl;
			k = check(1);
			int n;
			if (bank::count > 0)
			{
				cout << "Введите порядковый номер клиента в базе, от 1 до " << bank::count << endl;
				n = check(bank::count);
				if (k==1) operator+(all[n-1], plus);
				else operator+(all[n - 1], -plus);
			}
			else cout << "Сначала нужно добавить клиента в базу, выбрав соответсвующий пункт меню" << endl;
			break;
		}
		}
	} while (p != 6);
	// сохранение данных на диске
	all->save_klient(all, name);
	free(all);*/
	system("pause");
	return 0;
}