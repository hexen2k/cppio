#include <iostream>
#include <string>
#include "zadanie7.h"

using namespace std;

void zadanie7(void) {

	cout << "Wartosc nowej ustalonej liczby calkowitej wynosi: " << *(UstalLiczbeCalkowita()) << endl;
}

int * UstalLiczbeCalkowita(void) {
	int * pint = new int;

	cout << "Podaj liczbe calkowita: ";
	cin >> *pint;
	return pint;
}