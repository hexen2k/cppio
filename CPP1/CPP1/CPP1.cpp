// CPP1.cpp : Defines the entry point for the console application.

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
#if 0
#include "zadanie9.h"
#include "zadanie10.h"
#include "zadanie11.h"
#include "zadanie12.h"
#include "zadanie13.h"
#include "zadanie14.h"
#include "zadanie15.h"
#include "zadanie16.h"
#include "zadanie17.h"
#endif

using namespace std;

int main()
{
	int numer;

	cout << "C++ zestaw 1 - zestaw rozszerzony" << endl;
	cout << "Podaj numer zadania: ";
	cin >> numer;

	switch (numer) {
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
#if 0
		case 9:
			zadanie9();
			break;
		case 10:
			zadanie10();
			break;
		case 11:
			zadanie11();
			break;
		case 12:
			zadanie12();
			break;
		case 13:
			zadanie13();
			break;
		case 14:
			zadanie14();
			break;
		case 15:
			zadanie15();
			break;
		case 16:
			zadanie16();
			break;
		case 17:
			zadanie17();
			break;
#endif
		default:
			break;
	}
	
	cout << endl;
	system("pause");
    return 0;

}

