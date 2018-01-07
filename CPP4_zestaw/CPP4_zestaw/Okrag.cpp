#include "Okrag.h"
#include <iostream>


Okrag::~Okrag()
{
}

bool Okrag::Przeciecie(const Okrag &  okr) const
{
	double odleglosc_srodkow;
	if (X > okr.X)
	{
		odleglosc_srodkow = X - okr.X;
	}
	else
	{
		odleglosc_srodkow = okr.X - X;
	}
	if (R > okr.R)
	{
		return (R - okr.R < odleglosc_srodkow) && (odleglosc_srodkow < R + okr.R);
	}
	else
	{
		return (okr.R - R < odleglosc_srodkow) && (odleglosc_srodkow < R + okr.R);
	}
}

void Okrag::Wypisz(void) const
{
	std::cout << "OKRAG= srodek: " << X << " promien: " << R << " obwod:" << Obwod();
}

bool Okrag::StyczneWewnetrznie(const Okrag & okr) const
{
	double odleglosc_srodkow;
	if (X > okr.X)
	{
		odleglosc_srodkow = X - okr.X;
	}
	else
	{
		odleglosc_srodkow = okr.X - X;
	}
	if (R > okr.R)
	{
		return odleglosc_srodkow == (R - okr.R);
	}
	else
	{
		return odleglosc_srodkow == (okr.R - R);
	}
}

bool Okrag::StyczneZewnetrznie(const Okrag & okr) const
{
	double odleglosc_srodkow;
	if (X > okr.X)
	{
		odleglosc_srodkow = X - okr.X;
	}
	else
	{
		odleglosc_srodkow = okr.X - X;
	}
	return odleglosc_srodkow == (R + okr.R);
}

bool Kolo::StyczneWewnetrznie(const Kolo & kol) const
{
	if (Okrag::StyczneWewnetrznie(kol))
	{
		std::cout << "Roznica pol powierzchni dla kol stycznych wewnetrznie wynosi: ";
		if (GetR() > kol.Okrag::GetR())
		{
			std::cout << (Pole() - kol.Pole());
		}
		else
		{
			std::cout << (kol.Pole() - Pole());
		}
	}
	return Okrag::StyczneWewnetrznie(kol);
}

void Kolo::Wypisz(void) const
{
	std::cout << "KOLO= powierzchnia: " << Pole();
}

void Kula::Wypisz(void) const
{
	std::cout << "KULA= objetosc: " << Objetosc();
}
