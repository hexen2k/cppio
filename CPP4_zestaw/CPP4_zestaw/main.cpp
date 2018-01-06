#include <iostream>
#include "Pracownik.h"
#include "zadanie1.h"

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
		break;
	case 3:
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}