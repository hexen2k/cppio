#include <algorithm>
#include <iostream>
#include "zadanie3.h"
#include "Osoba.h"

using std::cout;
using std::cin;
using std::endl;

const int ILOSC_OSOB = 5;

bool cmpF(const Osoba * os1, const Osoba * os2)
{
	return 0 > strcmp(os1->GetNazwisko(), os2->GetNazwisko());
}

void zadanie3(void)
{
	int wybor = 0;
	int wiek = 0;
	int nr_leg = 0;
	char nazwisko[50];
	Osoba * person[ILOSC_OSOB];
	Student * sptr = NULL;
	cout << "Podaj kogo chcesz dodac:";
	for (int i = 0; i < ILOSC_OSOB; ++i)
	{
		cout << "1 Osoba, 2 Student: ";
		cin >> wybor;
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout << "Podaj wiek: ";
		cin >> wiek;
		switch (wybor)
		{
		case 1:
			person[i] = new Osoba(nazwisko, wiek);
			break;
		case 2:
			cout << "Podaj nr legitymacji: ";
			cin >> nr_leg;
			person[i] = new Student(nazwisko, wiek, nr_leg);
			sptr = dynamic_cast<Student *>(person[i]);	//RTTI test, pointer downcasting
			if(sptr) sptr->WprowadzSrednieOcen();
			break;
		default:
			--i;
			break;
		}
	}
	std::sort(person, person + sizeof(person) / sizeof(*person), cmpF);
	for (int i = 0; i < ILOSC_OSOB; ++i)
	{
		person[i]->PrzedstawSie();
		cout << endl;
		delete person[i];
	}
}
