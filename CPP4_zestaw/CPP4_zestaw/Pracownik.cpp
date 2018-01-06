#include "Pracownik.h"

Pracownik::Pracownik()
{
}

Pracownik::~Pracownik()
{
}

double Urzednik::KosztMiesieczny(void)
{
	return Pensja + Premia;
}

void Urzednik::Wprowadz(void)
{
	std::cout << "Podaj nazwisko urzednika: ";
	std::cin >> Nazwisko;
	std::cout << "Podaj miesieczna kwote pensji: ";
	std::cin >> Pensja;
	std::cout << "Podaj miesieczna kwote premii: ";
	std::cin >> Premia;
	
}

void Urzednik::Pokaz(void)
{
	std::cout << "Urzednik " << Nazwisko << " Pensja: " << Pensja << " zl, Premia: " << Premia << " zl" << " W sumie: " << Pensja + Premia << " zl";
}

void Robotnik::Wprowadz(void)
{
	std::cout << "Podaj nazwisko robotnika: ";
	std::cin >> Nazwisko;
	std::cout << "Podaj miesieczna kwote pensji: ";
	std::cin >> Pensja;
	std::cout << "Podaj miesieczna stawke % premii: ";
	std::cin >> Premia;
	
}

void Robotnik::Pokaz(void)
{
	std::cout << "Robotnik " << Nazwisko << " Pensja: " << Pensja << " zl, Premia: " << Premia << " %" << " W sumie: " << Pensja + (Pensja*Premia/100) << " zl";
}

double Robotnik::KosztMiesieczny(void)
{
	return Pensja + (Pensja * Premia / 100);
}
