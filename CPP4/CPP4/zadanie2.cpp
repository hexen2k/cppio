#include <iostream>
#include "zadanie2.h"
#include "Ssak.h"

void zadanie2(void)
{
	//Ssak zwierz;
	Pies kundel;
	Kot kitek;
	//std::cout << zwierz.rasa << "to jego rasa" << std::endl;
	kundel.Mow();
	std::cout << kundel.rasa << " to jego rasa jako psa" << std::endl;
	std::cout << kundel.Ssak::rasa << " to jego rasa jako ssaka" << std::endl;
	kitek.Mow();
	std::cout << kitek.rasa << " to jego rasa" << std::endl;
}
