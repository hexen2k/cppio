#include <iostream>
#include <string>
#include "zadanie6.h"

using namespace std;

const int TABLE_SIZE = 10;

//w komentarzu podano alternatywna notacje 
void zadanie6(void) {

	struct Wiz_t {
		int x;
		char k[10];
	};

	struct Wiz_t **pWiz = new struct Wiz_t *[TABLE_SIZE];

	for (int i = 0; i <TABLE_SIZE; i++) {
		//pWiz[i] = new struct Wiz_t;
		*(pWiz + i) = new struct Wiz_t;
		cout << "podaj x: ";
		//cin >> pWiz[i]->x;
		cin >> (*(*(pWiz + i))).x;
		cout << "podaj k[]: ";
		//cin >> pWiz[i]->k;
		cin >> (*(*(pWiz + i))).k;
	}

	for (int i = 0; i <TABLE_SIZE; i++) {
		//cout << "wartosc x= " << pWiz[i]->x << endl;
		cout << "wartosc x= " << (*(*(pWiz+i))).x << endl;
		//cout << "wartosc k= " << pWiz[i]->k << endl;
		cout << "wartosc k= " << (*(*(pWiz+i))).k << endl;
		//delete pWiz[i];
		delete [] *(pWiz+i);
	}
	delete [] pWiz;

}
