// CPP4.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Ssak.h"
#include "zadanie1.h"
#include "zadanie2.h"
#include "zadanie3.h"
#include "zadanie4.h"
#include "zadanie5.h"

using namespace std;

int main()
{
	int nr_zadania;

	cout << "Podaj numer zadania: ";
	cin >> nr_zadania;
	switch (nr_zadania)
	{
	case 1:
		zadanie1();
		break;
	case 2:
		zadanie2();
		break;
	case 3:
		zadanie3();
		break;
	case 4:
		zadanie4();
		break;
	case 5:
		zadanie5();
		break;
	default:
		break;
	}
	system("pause");
    return 0;
}

