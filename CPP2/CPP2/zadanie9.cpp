#include <iostream>
#include <string>
#include "zadanie9.h"

using namespace std;

struct listaw_t {
	struct listaw_t * next;
	float wynik_egzaminu;
};
struct student_t {
	string nazwa_kierunku;
	int rok_studiow;
	struct listaw_t lista_wynikow;
};

void dodaj_egzaminy(struct student_t * pstudent, int ilosc) {
	struct listaw_t * plistaw = &(pstudent->lista_wynikow);

	if (ilosc == 0) {
		cout << "Brak egzaminow!"<< endl;
		plistaw->wynik_egzaminu = 0.0;
		plistaw->next = NULL;
		return;
	}
	cout << "Podaj wyniki rozdzielone spacja: ";
	while (ilosc--) {
		cin >> plistaw->wynik_egzaminu;
		if (ilosc > 0) {	//przy ostatnim elemencie nie dodaje sie kolejnego wezla listy
			plistaw->next = new struct listaw_t;
			plistaw = plistaw->next;
		}
		plistaw->next = NULL;
	}
}

void wyswietl_egzaminy(struct student_t * pstudent) {
	struct listaw_t * plistaw = &(pstudent->lista_wynikow);
	while (plistaw) {
		cout << plistaw->wynik_egzaminu << " ";
		plistaw = plistaw->next;
	}
}

void posprzataj_po_studentach(struct listaw_t * plistaw) {
	struct listaw_t * oldplistaw;

	plistaw = plistaw->next;
	while (plistaw) {
		oldplistaw = plistaw;
		plistaw = plistaw->next;
		delete oldplistaw;
		oldplistaw = NULL;
	}
}

void zadanie9(void) {
	int ilosc_studentow, ilosc_egzaminow;

	cout << "Podaj ilosc studentow: ";
	cin >> ilosc_studentow;
	struct student_t ** student = new struct student_t *[ilosc_studentow];
	
	for (int i = 0; i < ilosc_studentow; i++) {
		student[i] = new struct student_t;
		cout << "Dane dla " << i + 1 << " studenta" << endl;
		cout << "Nazwa kierunku: ";
		cin >> student[i]->nazwa_kierunku;
		cout << "Rok studiow: ";
		cin >> student[i]->rok_studiow;
		cout << "Ilosc egzaminow: ";
		cin >> ilosc_egzaminow;
		dodaj_egzaminy(student[i], ilosc_egzaminow);
	}
	for (int i = 0; i < ilosc_studentow; i++) {
		cout << "Student " << i + 1 << ": kierunek: " << student[i]->nazwa_kierunku << " rok: " << student[i]->rok_studiow<<" oceny z egzaminow: ";
		wyswietl_egzaminy(student[i]);
		cout << endl;
		posprzataj_po_studentach(&(student[i]->lista_wynikow));	//usun wezly listy wynikow
		delete student[i];
		student[i] = NULL;
	}
	delete[] student;
	student = NULL;
}
