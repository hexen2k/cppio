#include <iostream>
#include <string>

#include "zadanie1.h"
#include "Pies.h"

using namespace std;

//klasy i obiekty

void zadanie1(void) {

	Pies wilczur("Szarik");
	Pies jamnik;
	jamnik.setImie("Rambo");

	cout << wilczur.imie << endl;
	cout << jamnik.imie << endl;
	wilczur.Spaceruj();
	jamnik.Spaceruj();
	wilczur.Jedz();
	jamnik.setImie("Rambunio");
	jamnik.Jedz();
}
