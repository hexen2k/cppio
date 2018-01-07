#include <iostream>
#include "Pracownik.h"
#include "zadanie1.h"
#include "zadanie2.h"
#include "zadanie3.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
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
	default:
		break;
	}

	system("pause");
	return 0;
}