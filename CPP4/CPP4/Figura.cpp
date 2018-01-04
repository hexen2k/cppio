#include "Figura.h"
#include <iostream>
#include <string>


Figura::Figura()
{
}


Figura::~Figura()
{
}

std::string Figura::nazwa(void)
{
	std::string tmp;
	return tmp;
}

double Figura::pole(void)
{
	return 0;
}

void Figura::wypisz(void)
{
	std::cout << Figura::nazwa() << " o polu " << Figura::pole();
}
