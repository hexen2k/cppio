// CPP2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "zadanie1.h"
#include "zadanie2.h"
#include "zadanie3.h"
#include "zadanie4.h"
#include "zadanie5.h"
#include "zadanie6.h"
#include "zadanie7.h"
#include "zadanie8.h"


using namespace std;


int main()
{
	int nr_zadania;
	
	cout << "Podaj nr zadania: ";
	cin >> nr_zadania;

	switch (nr_zadania) {
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
	case 6:
		zadanie6();
		break;
	case 7:
		zadanie7();
		break;
	case 8:
		zadanie8();
		break;
	default:
		break;
	}
	
	system("pause");
    return 0;
}

