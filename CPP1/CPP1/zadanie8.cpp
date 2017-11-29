#include "zadanie8.h"

void zadanie8(void) {

	static int znaki[255];
	string bufor_znakowy;
	int dlugosc_bufora;

	cout << "Prosze podac tekst z klawiatury dla ktorego zostanie utworzona statystyka wystapienia poszczegolnych liter:" << endl;
	cin >> bufor_znakowy;

	dlugosc_bufora = bufor_znakowy.length();
	for (int i = 0; i < dlugosc_bufora; i++) {
		if (bufor_znakowy.at(i) <= 'Z' && bufor_znakowy.at(i) >= 'A') {	//simple tolower
			znaki[bufor_znakowy.at(i) - ('Z' - 'z')]++;
		}
		else {
			znaki[bufor_znakowy.at(i)]++;
		}
	}
	for (int i = 0; i < 255; i++) {
		if (znaki[i]) {
			cout << (char)i << " <--- " << znaki[i] << "x" << endl;
		}
	}
}
