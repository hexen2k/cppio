// CPP3_podsumowujace.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "zadanie1.h"


int main()
{
	int nr_zadania;

	std::cout << "Podaj numer zadania: ";
	std::cin >> nr_zadania;
	switch (nr_zadania)
	{
	case 1:
		zadanie1();
		break;
	case 2:
		break;
	default:
		break;
	}
	system("pause");
    return 0;
}

