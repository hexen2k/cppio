#include <iostream>
#include <string>
#include "zadanie1.h"

using namespace std;

void zadanie1(void) {
	int var = 0;
	int *pvar = &var;

	cout << "Podaj wartosc dla zmiennej: ";
	cin >> *pvar;

	cout << "wartosc zmiennej var=" << var << endl<< " wartosc zmiennej wskazywanej prez pvar=" << *pvar << endl;
}