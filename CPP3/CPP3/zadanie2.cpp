#include <iostream>
#include <string>

#include "zadanie1.h"
#include "Pies.h"

//konstruktory

using namespace std;

void zadanie2(void) {

	Pies wilczur;
	Pies burek = Pies();
	Pies *wsk = new Pies();

	burek.setImie("Reksio");
	burek.setBarwa(czarny);

	wsk->imie = "Szotek";
	wsk->barwa = bialy;
	wsk->setBarwa(szary);

	burek.Spaceruj();
	burek.Jedz();
	cout << "Energia burka:" << burek.energia << endl;

	wsk->Spaceruj();
	(*wsk).Jedz();
	cout << "Energia szotka:" << wsk->energia << endl;
	
	Pies husky(70,"Max"); //lub Pies husky = Pies(70);
	husky.Jedz();
	husky.Jedz();

	Pies jamnik(bialy, 20);
	jamnik.Spaceruj();

	husky.setBarwa(czarny);

	Pies wilk((*wsk));
	husky.Jedz();
	wilk.Jedz();
	wilk.setImie("Wilkor");
	wilk.Jedz();
	husky.Jedz();
}