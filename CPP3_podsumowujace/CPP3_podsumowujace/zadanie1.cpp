#include "zadanie1.h"
#include "LiczbaZespolona.h"
#include <iostream>


void zadanie1(void)
{
	LiczbaZespolona ** pZespolona = new LiczbaZespolona *[100];
	for (int i = 0; i < 100; i++)
	{
		pZespolona[i] = nullptr;
	}
	char command = 0;
	int indexForReading = 0;
	int indexForWriting = 0;
	double Re, Im;
	while (command != 'K')
	{
		//system("cls");	//clear screen
		std::cout << "Podaj polecenie (N,R,W,+,-,*,=) lub K aby zakonczyc: ";
		std::cin >> command;
		switch (command)
		{
		case 'N':
			pZespolona[indexForWriting++] = new LiczbaZespolona(2.0, 2.0);
			std::cout << "Zapisano pod indeks nr " << indexForWriting-1 << std::endl;
			break;
		case 'R':
			pZespolona[indexForWriting++] = new LiczbaZespolona(1.0);
			std::cout << "Zapisano pod indeks nr " << indexForWriting-1 << std::endl;
			break;
		case 'W':
			std::cout << "Podaj indeks do tablicy liczb zespolonych w celu wyswietlenia liczby: ";
			std::cin >> indexForReading;
			if (pZespolona[indexForReading])
			{
				std::cout << *pZespolona[indexForReading] << std::endl;
			}
			else
			{
				std::cout << "Brak liczby zespolonej w tablica[" << indexForReading << "]" << std::endl;
			}
			break;
		case '+':
			{
				std::cout << "Podaj Re dla pierwszej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla pierwszej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z1(Im, Re);
				std::cout << "Podaj Re dla drugiej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla drugiej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z2(Im, Re);
				pZespolona[indexForWriting] = new LiczbaZespolona();
				pZespolona[indexForWriting]->AddTwo(z1,z2);
				std::cout << "Wynik dodawania: " << *pZespolona[indexForWriting] << " zapisano pod indeksem: " << indexForWriting << std::endl;
				indexForWriting++;
			}
			break;
		case '-':
			{
				std::cout << "Podaj Re dla pierwszej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla pierwszej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z1(Im, Re);
				std::cout << "Podaj Re dla drugiej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla drugiej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z2(Im, Re);
				pZespolona[indexForWriting] = new LiczbaZespolona();
				pZespolona[indexForWriting]->SubTwo(z1,z2);
				std::cout << "Wynik odejmowania: " << *pZespolona[indexForWriting] << " zapisano pod indeksem: " << indexForWriting << std::endl;
				indexForWriting++;
			}
			break;
		case '*':
			{
				std::cout << "Podaj Re dla pierwszej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla pierwszej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z1(Im, Re);
				std::cout << "Podaj Re dla drugiej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla drugiej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z2(Im, Re);
				pZespolona[indexForWriting] = new LiczbaZespolona();
				pZespolona[indexForWriting]->MulTwo(z1,z2);
				std::cout << "Wynik mnozenia: " << *pZespolona[indexForWriting] << " zapisano pod indeksem: " << indexForWriting << std::endl;
				indexForWriting++;
			}
			break;
		case '=':
			{
				std::cout << "Podaj Re dla pierwszej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla pierwszej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z1(Im, Re);
				std::cout << "Podaj Re dla drugiej liczby: ";
				std::cin >> Re;
				std::cout << "Podaj Im dla drugiej liczby: ";
				std::cin >> Im;
				LiczbaZespolona z2(Im, Re);
				std::cout << "Wynik porownania: ";
				//if (Equal(z1, z2))	//done by extern function
				//if (z1.Eq(z2))	//dony by class method
				if(z1==z2)	//done by overloaded == operator
				{
					std::cout << "TAKIE SAME" << std::endl;
				}
				else
				{
					std::cout << "ROZNE" << std::endl;
				}
			}
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		delete pZespolona[i];
	}
	delete[] pZespolona;
}
