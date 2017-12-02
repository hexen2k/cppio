#include <iostream>
#include <string>
#include "zadanie2.h"

using namespace std;

void zadanie2(void) {
	struct Wiz {
		int x;
		char k[10];
	};
	struct Wiz * pWiz;

	struct Wiz a;
	pWiz = &a;

	cout << "Podaj x:";
	cin >> a.x;
	cout << "Wartosc x=" << pWiz->x;

	cout << "Podaj k:";
	cin >> pWiz->k;
	cout << "Wartosc tablicy k=" << a.k;

}