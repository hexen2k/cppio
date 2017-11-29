#include "zadanie7.h"
#include <conio.h>

const int ILOSC_DANYCH = 5;
const int MAX_DLUGOSC_CIAGU_ZNAKOWEGO = 20;
const int ESC_CODE = 27;
const int ENTER_CODE = 13;

void zadanie7(void) {

	char ch;
	int ilosc_wprowadzonych = 0;
	struct dane_osobowe_t {
		string imie;
		string nazwisko;
		int kod;
		string miejscowosc;
		string ulica;
	} dane_osobowe_tab[ILOSC_DANYCH];

	for (int i = 0; i < ILOSC_DANYCH; i++) {
		cout << "Podaj imie lub wcisnij klawisz ESC aby anulowac dalsze wprowadzanie: " << endl;
		while ((ch = _getch()) != ESC_CODE){
			if (ch == ENTER_CODE) {
				cout << endl;
				break;
			}
			cout << ch; //simple bypass for terminal
			dane_osobowe_tab[i].imie += ch; //append to string
		}
		if (ch == ESC_CODE) break;
		cout << "Podaj nazwisko: ";
		cin >> dane_osobowe_tab[i].nazwisko;
		cout << "Podaj kod pocztowy (jako liczbe 5 cyfrowa): ";
		cin >> dane_osobowe_tab[i].kod;
		cout << "Podaj miejscowosc: ";
		cin >> dane_osobowe_tab[i].miejscowosc;
		cout << "Podaj ulice: ";
		cin >> dane_osobowe_tab[i].ulica;
		ilosc_wprowadzonych++;
	}
	for (int i = 0; i < ilosc_wprowadzonych; i++) {
		cout.width(MAX_DLUGOSC_CIAGU_ZNAKOWEGO);
		cout << left << dane_osobowe_tab[i].imie;
		cout.width(MAX_DLUGOSC_CIAGU_ZNAKOWEGO);
		cout << left << dane_osobowe_tab[i].nazwisko;
		cout << endl;
		cout.width(MAX_DLUGOSC_CIAGU_ZNAKOWEGO);
		cout << left << dane_osobowe_tab[i].ulica;
		cout.width(MAX_DLUGOSC_CIAGU_ZNAKOWEGO);
		cout << left << dane_osobowe_tab[i].kod;
		cout.width(MAX_DLUGOSC_CIAGU_ZNAKOWEGO);
		cout << left << dane_osobowe_tab[i].miejscowosc;
		cout << endl << endl;
	}
}