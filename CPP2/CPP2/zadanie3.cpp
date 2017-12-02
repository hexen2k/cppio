#include <iostream>
#include <string>
#include "zadanie3.h"

using namespace std;

void zadanie3(void) {

	int * pvar = new int;

	cout << "Podaj wartosc zmiennej:";
	cin >> *pvar;
	cout << endl << "Wartosc zmiennej wynosi: " << *pvar << endl;
	delete pvar;
	pvar = NULL;
}