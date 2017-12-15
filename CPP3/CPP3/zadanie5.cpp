#include <iostream>
#include <string>
#include "zadanie5.h"
#include "Pies.h"

using namespace std;

void zadanie5(void) {
	Pies wilczur("Szarik");
	wilczur.Spaceruj();
	//wilczur.Spaceruj(21);
	//wilczur.Spaceruj(2.4);
	wilczur.Spaceruj(30, 2.4);
	wilczur.Spaceruj(20);	//godziny podstawiane wartoscia domyslna
	wilczur.Spaceruj(6.3);	//rzutowanie zmiennej 6.3 typu double na int => 6 ORAZ godziny podstawiane wartoscia domyslna
}
