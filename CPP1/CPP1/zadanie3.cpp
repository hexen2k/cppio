#include "zadanie3.h"

int tablica[1000];

void zadanie3(void) {
	int liczba, kolejna_liczba;
	string wynik = "TAK";

	cout << "Podaj ilosc wprowadzanych liczb: ";
	cin >> liczba;
	if (liczba >= 1000) {
		cout << "BLAD: Liczba calkowita wieksza lub rowna 1000";
		return;
	}

	cout << "Podaj liczby odseparowane spacja: ";
	for (int i = 0; i < liczba; i++) {
		cin >> kolejna_liczba;
		tablica[kolejna_liczba]++;
	}

	for (int i = 1; i <= liczba; i++) {
		if (tablica[i] != 1) {
			wynik = "NIE";
		}
	}
	cout << wynik;
}