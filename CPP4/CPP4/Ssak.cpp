#include <iostream>
#include "Ssak.h"

Ssak::Ssak()
{
	rasa = "Ssak";
}

Ssak::~Ssak()
{
}

void Ssak::Jedz(void)
{
	std::cout << "Ssak je" << std::endl;
}

void Ssak::Mow(void)
{
	std::cout << "Ssak mowi";
}

Pies::Pies()
{
	imie = "imiepsa";
	rasa = "Nienazwany Pies";
}

void Pies::Mow(void)
{
	std::cout << "hau" << std::endl;
}

void Husky::Biegaj(void)
{
	std::cout << "husky_biega";
}

Kot::Kot()
{
	rasa = "Nienazwany Kot";
}

void Kot::Mow(void)
{
	std::cout << "miau" << std::endl;
}