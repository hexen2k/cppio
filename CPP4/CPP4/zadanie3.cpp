#include <string>
#include "zadanie3.h"
#include "Samochod.h"

void zadanie3(void)
{
	Samochod opel("Astra", 30, 160, 8.5);
	opel.Jedz(200,200);
	Kabriolet audi("A5", 30, 160, 8.5);
	audi.Jedz(200, 200);
	audi.otworz_dach();
	audi.Jedz(200, 350);
	audi.zamknij_dach();
	audi.Jedz(200, 350);

}
