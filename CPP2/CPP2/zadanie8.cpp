#include <iostream>
#include <string>
#include "zadanie8.h"

using namespace std;

void zadanie8(void) {

	char inbuff[1000];
	char inchar;
	char * wynik = NULL;

	cout << "Podaj ciag znakowy do przeszukania: " << endl;
	cin >> inbuff;
	cout << "Podaj wyszukiwany znak: " << endl;
	cin >> inchar;
	wynik = znajdz(inbuff, inchar);
	if (wynik != NULL) {
		cout << "Tekst wystepujacy po drugim wystapieniu wyszukiwanego znaku (pierwszy to szukany znak): " << endl;
		cout << wynik << endl;
	}
	else {
		cout << "Nie znaleziono drugieo wystpienia znaku!" << endl;
	}
}

char * znajdz(char *s, char c) {
	char * wynik = NULL;
	int cnt = 0;

	while (*s++ != '\0') {
		if (*s == c) {
			cnt++;
			if (cnt == 2) {
				wynik = s;
				break;
			}
		}
	}
	return wynik;
}
