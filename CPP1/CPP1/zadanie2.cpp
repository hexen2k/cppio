#include "zadanie2.h"

void zadanie2(void) {

	int n = 1;
	int liczba;

	cout << "Podaj liczbe naturalna n (1<n<100) ";
	cin >> liczba;

	if (liczba < 1 || liczba > 100) {
		cout << "BLAD: Podales liczbe poza zakresem";
		return;
	}
	
	for (int i = 0; i < liczba; i++) {
		if (i % 2) {	//wiersze nieparzyste
			n += liczba - 1;
			for (int i = 0; i < liczba; i++) {
				cout << n-- << " ";
			}
			n += liczba + 1;
		}
		else {	//wiersze parzyste
			for (int i = 0; i < liczba; i++) {
				cout << n++ << " ";
			}
		}
		cout << endl;
	}
}