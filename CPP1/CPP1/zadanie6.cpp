#include "zadanie6.h"

void zadanie6(void) {
	int n;
	double ciag = 0;

	cout << "Podaj wartosc n dla obliczenia ciagu harmonicznego: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		ciag += 1.0 / i;
	}
	cout << "Obliczona wartosc ciagu harmonicznego wynosi: " << ciag;
}