#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "zadanie10.h"

using namespace std;

struct osoba_t {
	string imie;
	string nazwisko;
	int wiek;
	struct osoba_t * next;
};

struct osobatab_t {
	string imie;
	string nazwisko;
	int wiek;
};

void zadanie10(void) {
	int exitflag = 1;
	int wybor;
	string sciezka;
	string przenoszonenazwisko;
	string usuwanenazwisko;
	struct osoba_t *wosoba = NULL;
	struct osoba_t **wwosoba = &wosoba;
	struct osobatab_t *wosobatab = NULL;
	struct osobatab_t **wwosobatab = &wosobatab;

	int rozmiar_tablicy_dynamicznej = 0;

	cout << "Podaj sciezke do pliku: ";
	cin >> sciezka;
	wczytaj_z_pliku(sciezka, wwosoba);
	rozmiar_tablicy_dynamicznej = konwertuj_liste_na_tablice(wwosoba, wwosobatab);
	while (exitflag) {
		cout << "1: dodaj element do listy, 2: przenies z listy do tablicy, 3: usun element z tablicy, 4: wypisz zawartosc listy i tablicy, 5: wyjscie" << endl;
		cin >> wybor;
		switch (wybor) {
		case 1:
			dodaj_element_do_listy(wwosoba);
			break;
		case 2:
			cout << "Podaj nazwisko do przeniesienia z listy do tablicy: ";
			cin >> przenoszonenazwisko;
			rozmiar_tablicy_dynamicznej = przenies_z_listy_do_tablicy(wwosoba, wwosobatab, rozmiar_tablicy_dynamicznej, przenoszonenazwisko);
			break;
		case 3:
			cout << "Podaj nazwisko do usuniecia z tablicy: ";
			cin >> usuwanenazwisko;
			rozmiar_tablicy_dynamicznej = usun_element_z_tablicy(wwosobatab, rozmiar_tablicy_dynamicznej, usuwanenazwisko);
			break;
		case 4:
			wypisz_liste_i_tablice(wwosoba, wwosobatab, rozmiar_tablicy_dynamicznej);
			break;
		default:
			posprzataj_pamiec(wwosoba, wwosobatab);
			exitflag = 0;
			break;
		}
	}
}

void wczytaj_z_pliku(string sciezkadopliku, struct osoba_t **wosoba) {
	ifstream mojplik;
	string linia;
	struct osoba_t *prevwosoba = NULL;
	struct osoba_t *firstosoba = NULL;

	mojplik.open(sciezkadopliku);
	if (mojplik.is_open()) {
		*wosoba = new struct osoba_t;
		firstosoba = *wosoba;
		cout << "WCZYTANE Z PLIKU:" << endl;
		while (getline(mojplik, linia)) {
			istringstream iss(linia);
			iss >> (*wosoba)->imie; //iss >> (*(*wosoba)).imie;
			iss >> (*wosoba)->nazwisko;
			iss >> (*wosoba)->wiek;
			cout << (*wosoba)->imie << " " << (*wosoba)->nazwisko << " " << (*wosoba)->wiek << endl;
			prevwosoba = (*wosoba);
			(*wosoba)->next = new struct osoba_t;
			(*wosoba) = (*wosoba)->next;
		}
	delete (*wosoba);
	(*wosoba) = NULL;
	prevwosoba->next = NULL;	//terminate list
	*wosoba = firstosoba;
	}
	else {
		cout << "Otwarcie pliku do odczytu nie powiodlo sie!" << endl;
	}
	mojplik.close();
}

void dodaj_element_do_listy(struct osoba_t **wosoba) {
	struct osoba_t *firstwosoba = *wosoba;

	if (*wosoba == NULL) { //list empty
		*wosoba = new struct osoba_t;
		cout << "Podaj imie: ";
		cin >> (*wosoba)->imie;
		cout << "Podaj nazwisko: ";
		cin >> (*wosoba)->nazwisko;
		cout << "Podaj wiek: ";
		cin >> (*wosoba)->wiek;
		(*wosoba)->next = NULL;
	}
	else {
		while ((*wosoba)->next != NULL) {
			*wosoba = (*wosoba)->next;
		}
		(*wosoba)->next = new struct osoba_t;
		*wosoba = (*wosoba)->next;
		cout << "Podaj imie: ";
		cin >> (*wosoba)->imie;
		cout << "Podaj nazwisko: ";
		cin >> (*wosoba)->nazwisko;
		cout << "Podaj wiek: ";
		cin >> (*wosoba)->wiek;
		(*wosoba)->next = NULL;
		*wosoba = firstwosoba;
	}
}

int konwertuj_liste_na_tablice(struct osoba_t **wosoba, struct osobatab_t **wosobatab) {
	int liczba_wezlow = 0;
	struct osoba_t *firstosoba = *wosoba;
	struct osobatab_t *firstelement = NULL;
	while (*wosoba != NULL) {
		*wosoba = (*wosoba)->next;
		liczba_wezlow++;
	}
	*wosoba = firstosoba;
	if (*wosobatab == NULL) {
		*wosobatab = new struct osobatab_t[liczba_wezlow];
	}
	else {
		delete[] * wosobatab;
		*wosobatab = new struct osobatab_t[liczba_wezlow];
	}
	firstelement = *wosobatab;
	*wosoba = firstosoba;
	for (int i = 0; i < liczba_wezlow; i++) {
		(*(*wosobatab+i)).imie = (*wosoba)->imie;
		(*(*wosobatab+i)).nazwisko = (*wosoba)->nazwisko;
		(*(*wosobatab+i)).wiek = (*wosoba)->wiek;
		*wosoba = (*wosoba)->next;
	}
	*wosoba = firstosoba;
	*wosobatab = firstelement;
	return liczba_wezlow;
}

int przenies_z_listy_do_tablicy(struct osoba_t **wosoba, struct osobatab_t **wosobatab, int ilosc_elementow, string nazwisko) {
	struct osoba_t *firstnode = *wosoba;
	struct osoba_t *prevnode = *wosoba;
	struct osobatab_t *firsttabelement = *wosobatab;
	struct osobatab_t *nowatablica = NULL;

	while (*wosoba != NULL) {
		if (nazwisko == (*wosoba)->nazwisko) {
			break;
		}
		prevnode = *wosoba;
		*wosoba = (*wosoba)->next;
	}
	if (*wosoba != NULL) {
		ilosc_elementow++;
		nowatablica = new struct osobatab_t[ilosc_elementow];
		for (int i = 0; i < ilosc_elementow-1; i++) {
			nowatablica[i].imie = (*(*wosobatab + i)).imie;
			nowatablica[i].nazwisko = (*(*wosobatab + i)).nazwisko;
			nowatablica[i].wiek = (*(*wosobatab + i)).wiek;
		}
		delete[] * wosobatab;
		*wosobatab = nowatablica;
		nowatablica[ilosc_elementow - 1].imie = (*wosoba)->imie;
		nowatablica[ilosc_elementow - 1].nazwisko = (*wosoba)->nazwisko;
		nowatablica[ilosc_elementow - 1].wiek = (*wosoba)->wiek;
		prevnode->next = (*wosoba)->next;
		if (firstnode == *wosoba) { //moved node is the first element
			firstnode = (*wosoba)->next;
		}
		delete *wosoba;
		*wosoba = NULL;
	}
	*wosoba = firstnode;
	return ilosc_elementow;
}

int usun_element_z_tablicy(struct osobatab_t **wosobatab, int liczbaelementow, string nazwisko) {
	struct osobatab_t *nowatablica = NULL;
	int i, j, k;
	for (i = 0; i < liczbaelementow; i++) {
		if (nazwisko == (*(*wosobatab + i)).nazwisko) {
			//i--; //TODO: for loop, if break skip i++?
			break;
		}
	}
	if (liczbaelementow != i) { //nazwisko znalezione w tablicy
		nowatablica = new struct osobatab_t[--liczbaelementow];
		for (j = k = 0; j < liczbaelementow; j++,k++) {
			if (j == i) {
				k++;	//skip found element
			}
			nowatablica[j].imie = (*(*wosobatab + k)).imie;
			nowatablica[j].nazwisko = (*(*wosobatab + k)).nazwisko;
			nowatablica[j].wiek = (*(*wosobatab + k)).wiek;
		}
		delete[] *wosobatab;
		*wosobatab = nowatablica;
	}
	return liczbaelementow;
}

void wypisz_liste_i_tablice(struct osoba_t **wosoba, struct osobatab_t **wosobatab, int liczba_elementow) {
	struct osoba_t *copywosoba = *wosoba;
	struct osobatab_t *copywosobatab = *wosobatab;

	cout << "ZAWARTOSC LISTY:" << endl;
	while ((*wosoba) != NULL) {
		cout << (*wosoba)->imie << " " << (*wosoba)->nazwisko << " " << (*wosoba)->wiek << endl;
		*wosoba = (*wosoba)->next;
	}
	cout << "ZAWARTOSC TABLICY DYNAMICZNEJ:" << endl;
	for (int i = 0; liczba_elementow--; i++) {
		cout << (*(*wosobatab + i)).imie << " " << (*(*wosobatab + i)).nazwisko << " " << (*(*wosobatab + i)).wiek << endl;
	}
	*wosoba = copywosoba;
	*wosobatab = copywosobatab;
}

void posprzataj_pamiec(struct osoba_t **wosoba, struct osobatab_t **wosobatab) {
	struct osoba_t *ptmp = NULL;

	delete[] *wosobatab;
	while (*wosoba != NULL) {
		ptmp = *wosoba;
		(*wosoba) = (*wosoba)->next;
		delete ptmp;
		ptmp = NULL;
	}
}
