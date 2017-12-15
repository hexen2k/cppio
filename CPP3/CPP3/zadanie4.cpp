#include <iostream>
#include <string>
#include "zadanie4.h"
#include "Zespolona.h"

//przeciazanie operatorow

using namespace std;

void zadanie4(void) {
	Zespolona z;
	cout << z << endl;

	Zespolona z1, z2;
	z = z1 + z2;
	cout << z << endl;

	z1 += z2;
	cout << z1 << endl;

	Zespolona z3, z4;
	z3 = z3 + z4;
	z4 = z4 + z4;
	z = z3 * z4;
	cout << z << endl << "z3=" << z3 << endl << "z4=" << z4;
}
