#include <iostream>
#include <string>
#include "zadanie5.h"

using namespace std;

const int TAB_SIZE = 10;

void zadanie5(void) {

	int **pint = new int *[TAB_SIZE];

	cout << "Podaj " << TAB_SIZE << " wartosci:";

	for (int i = 0; i <TAB_SIZE; i++) {
		//pint[i] = new int;
		*(pint+i) = new int;
		//cin >> *pint[i];
		cin >> *(*(pint+i));
	}

	for (int i = 0; i <TAB_SIZE; i++) {
		//cout << *pint[i] << endl;
		cout << *(*(pint+i)) << endl;
		delete [] pint[i];
		pint[i] = NULL;
	}
	delete [] pint;
	pint = NULL;
}