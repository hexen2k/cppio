#include <iostream>
#include "zadanie5.h"
#include "Ssak.h"

void zadanie5(void)
{
	//Ssak ssak1;
	//ssak1.Mow();
	Pies pies1;
	pies1.Mow();
	Kot kot1;
	kot1.Mow();
	kot1.Ssak::Mow();
	std::cout << "-------" << std::endl;
	Husky husky1;
	husky1.Jedz();
	husky1.Mow();
	husky1.Biegaj();
}