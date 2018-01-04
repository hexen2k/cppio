#include <iostream>
#include "zadanie4.h"
#include "Figura.h"

void zadanie4(void)
{
	Figura trojkat;
	Kolo kolo1;
	kolo1.wypisz();
	kolo1.ustawPromien(20);
	std::cout << kolo1.promien();

}
