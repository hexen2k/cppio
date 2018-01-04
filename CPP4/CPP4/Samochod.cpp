#include <string>
#include <cmath>
#include <iostream>
#include "Samochod.h"

using std::cout;
using std::endl;

Samochod::~Samochod()
{
}

void Samochod::Jedz(double jakSzybko, double jakDaleko)
{
	double ilosc_potrzebnych_bakow;
	cout << "Samochod " << marka << " pojedzie: ";
	if (jakSzybko < predkosc_max)
	{
		cout << jakSzybko;
	}
	else
	{
		cout << predkosc_max;
	}
	cout << " km/h" << endl;
	cout << "Bedzie musial tankowac po drodze ";
	ilosc_potrzebnych_bakow = jakDaleko / 100.0 * zuzycie_paliwa / pojemnosc_baku;
	cout << ceil(ilosc_potrzebnych_bakow) << " raz(y)" << endl;
}

void Kabriolet::Jedz(double jakSzybko, double jakDaleko)
{
	if (dach_otwarty)
	{
		jakDaleko *= 1.15;	//z dachem otwartym 15% wieksze spalanie
	}
	Samochod::Jedz(jakSzybko, jakDaleko);
}
