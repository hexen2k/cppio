#include "zadanie4.h"

void zadanie4(void) {
	static int tab[100];
	int liczba_dni, max_trend = 0, max_diff = 0;

	cout << "Podaj liczbe dni: ";
	cin >> liczba_dni;
	cout << "Podaj wage w kolejnych dniach: " << endl;
	for (int i = 0; i < liczba_dni; i++) {
		cin >> tab[i];
		if (max_trend < tab[i]) {
			max_trend = tab[i];
		}
		if ((max_trend - tab[i]) > max_diff) {
			max_diff = max_trend - tab[i];
		}
	}

	cout << "Maksymalny spadek wagi Felka wynosi: " << max_diff << " kg.";

}