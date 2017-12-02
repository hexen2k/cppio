#include <iostream>
#include <string>
#include "zadanie4.h"

using namespace std;

void zadanie4(void) {
	struct Wiz_t{
		int x;
		char k[10];
	};

	struct Wiz_t * pWiz = new struct Wiz_t;

	cout << "Podaj wartosc x:";
	cin >> pWiz->x;
	cout << " Podaj wartosc k[]:";
	cin >> pWiz->k;

	cout << "wartosc x= " << pWiz->x << endl << "wartosc k[]=" << pWiz->k << endl;
	delete pWiz;
	pWiz = NULL;

}