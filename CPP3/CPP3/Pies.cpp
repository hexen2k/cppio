#include <iostream>
#include <string>
#include "Pies.h"

using namespace std;

Pies::Pies()
{
	Pies::imie = new char[1];
	Pies::energia = 50;
}

Pies::Pies(char * noweImie)
{
	int i = 0;
	while (noweImie[i]) i++;	//okresl dlugosc ciagu wejsciowego
	Pies::imie = new char [i+1];
	i = 0;
	while (noweImie[i] != '\0') {
		Pies::imie[i] = noweImie[i];
		i++;
	}
	Pies::imie[i] = noweImie[i];
}

Pies::Pies(int energia_poczatkowa) {
	Pies::imie = new char[1];
	Pies::imie[0] = '\0';
	Pies::energia = energia_poczatkowa;
}

Pies::Pies(int energia_poczatkowa, char * noweImie) {
	int i = 0;
	while (noweImie[i]) i++;	//okresl dlugosc ciagu wejsciowego
	Pies::imie = new char [i+1];
	i = 0;
	while (noweImie[i] != '\0') {
		Pies::imie[i] = noweImie[i];
		i++;
	}
	Pies::imie[i] = noweImie[i];
	Pies::energia = energia_poczatkowa;
}

Pies::Pies(enum barwa_e nowaBarwa, int energia_poczatkowa) {

	Pies::imie = new char[1];
	Pies::imie[0] = '\0';
	
	Pies::energia = energia_poczatkowa;
	Pies::barwa = nowaBarwa;
}

/* zad. 9
Pies::Pies(const Pies &pies) {
	int i = 0;
	while (pies.imie[i]) i++;	//okresl dlugosc ciagu wejsciowego
	Pies::imie = new char [i+1];
	i = 0;
	while (pies.imie[i] != '\0') {
		Pies::imie[i] = pies.imie[i];
		i++;
	}
	Pies::imie[i] = pies.imie[i];

	barwa = pies.barwa;
	energia = pies.energia + 3;
}
*/

//zad. 10
Pies::Pies(const Pies &pies) {
	int i = 0;
	const char * postfix = "_2";

	while (pies.imie[i]) i++;	//okresl dlugosc ciagu wejsciowego
	Pies::imie = new char [i+sizeof(postfix) + 1];

	//https://stackoverflow.com/questions/16883037/remove-secure-warnings-crt-secure-no-warnings-from-projects-by-default-in-vis
	strcpy(Pies::imie, pies.imie);
	strcat(Pies::imie, postfix);

	barwa = pies.barwa;
	energia = pies.energia + 3;
}

Pies::~Pies()
{
	delete [] Pies::imie;
	Pies::imie = NULL;
}

void Pies::setImie(char * noweImie)
{
	int i = 0;

	delete Pies::imie;
	while (noweImie[i]) i++;	//okresl dlugosc ciagu wejsciowego
	Pies::imie = new char[i + 1]; //dostosuj rozmiar do nowego imienia
	i = 0;
	while (noweImie[i] != '\0') {
		Pies::imie[i] = noweImie[i];
		i++;
	}
	Pies::imie[i] = noweImie[i];
}

void Pies::setBarwa(enum barwa_e nowaBarwa) {
	Pies::barwa = nowaBarwa;
}

void Pies::Spaceruj(void) {
	cout << Pies::imie << " spaceruje";
	Pies::energia -= 10;
	cout << " stan energii: " << Pies::energia << endl;
}
/*
void Pies::Spaceruj(int minuty) {
	cout << Pies::imie << " spaceruje " << minuty << " minut";
	Pies::energia -= 10;
	cout << " stan energii: " << Pies::energia << endl;
}

void Pies::Spaceruj(double godziny) {
	cout << Pies::imie << " spaceruje " << godziny << " godziny";
	Pies::energia -= 10;
	cout << " stan energii: " << Pies::energia << endl;
}
*/
void Pies::Spaceruj(int minuty, double godziny) {
	cout << Pies::imie << " spaceruje " << godziny << " godziny i " << minuty << " minut";
	Pies::energia -= 10;
	cout << " stan energii: " << Pies::energia << endl;
}

void Pies::Jedz(void) {
	cout << Pies::imie << " gryzie kosc";
	Pies::energia += 10;
	cout << " stan energii: " << Pies::energia << endl;
}

int Pies::IleEnergii() {
	return Pies::energia;
}