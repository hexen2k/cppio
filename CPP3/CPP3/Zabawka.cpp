#include <iostream>
#include <string>
#include "Zabawka.h"

int ile_zabawek;

Zabawka::Zabawka(char * nazwa_0) {
	nazwa = new char[20];
	strcpy(nazwa, nazwa_0);
	nr = ++ile_zabawek;
	std::cout << "Obiekt " << nazwa << " zostal utworzony, numer zbawki: " << nr << " -- W SUMIE: " << ile_zabawek << " ZABAWEK" << std::endl;
}

Zabawka::~Zabawka()
{
	ile_zabawek--;
	std::cout << "ZNISZCZONO: " << nazwa << " o numerze: " << nr << " -- W SUMIE: " << ile_zabawek << " ZABAWEK" << std::endl;
	delete[] nazwa; //w poleceniu Zad. 5 jest blad, pamiec nalezy zwolnic wersja delete[] (z klamrami) bo tak zostala zarezerwowana pamiec
}
