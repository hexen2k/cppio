#include <algorithm>
#include <iostream>
#include "zadanie2.h"
#include "Okrag.h"

const int ILOSC_OBIEKTOW = 10;

bool cmpF(const Okrag * o1, const Okrag * o2)
{
	return (o1->GetX() < o2->GetX());
}

void zadanie2(void)
{
	int wybor = 0;
	int iloscFigurZpktWspolnymi = 0;
	double promien;
	double polozenieX;
	Okrag * obiekt[ILOSC_OBIEKTOW];
	Okrag * obiektSort[ILOSC_OBIEKTOW];
	std::cout << "Podaj " << ILOSC_OBIEKTOW << " obiektow do tablicy" << std::endl;
	for (int i = 0; i < ILOSC_OBIEKTOW; i++)
	{
		std::cout << "1 Okrag, 2 Kolo, 3 Kula: ";
		std::cin >> wybor;
		std::cout << "Podaj promien: ";
		std::cin >> promien;
		std::cout << "Podaj polozenie srodka X: ";
		std::cin >> polozenieX;
		switch (wybor)
		{
		case 1:
			obiekt[i] = new Okrag(polozenieX, promien);
			break;
		case 2:
			obiekt[i] = new Kolo(polozenieX, promien);
			break;
		case 3:
			obiekt[i] = new Kula(polozenieX, promien);
			break;
		default:
			--i;
			break;
		}
	}
	for (int i = 0; i < ILOSC_OBIEKTOW; i++)
	{
		obiektSort[i] = obiekt[i];
	}
	std::sort(obiektSort, obiektSort + sizeof(obiektSort) / sizeof(*obiektSort), cmpF);
	for (int i = 0; i < ILOSC_OBIEKTOW; ++i)
	{
		int tmp = 0;
		for (int j = 0; j < ILOSC_OBIEKTOW; ++j)
		{
			if (i == j) continue; //skip comparing with himself
			if (obiekt[i]->Przeciecie(*obiekt[j]) || obiekt[i]->StyczneWewnetrznie(*obiekt[j]) || obiekt[i]->StyczneZewnetrznie(*obiekt[j]))
			{
				++tmp;
			}
		}
		if(tmp)	++iloscFigurZpktWspolnymi;
	}
	std::cout << "Znaleziono " << iloscFigurZpktWspolnymi << " figur(y) z punktami wspolnymi" << std::endl;
	for (int i = 0; i < ILOSC_OBIEKTOW; i++)
	{
		obiektSort[i]->Wypisz();
		//obiektSort[i]->Okrag::Wypisz(); //DBG
		std::cout << std::endl;
		delete obiektSort[i];
	}
}
