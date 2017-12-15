#include <iostream>
#include <string>
#include "zadanie3.h"
#include "Zabawka.h"

using namespace std;

//desktruktory

void zadanie3(void) {
	Zabawka kaczuszka("Donald");
	Zabawka piesek("Reksio");
	Zabawka krolik = Zabawka("Baks");
	{
		Zabawka misio("Pluszk");
		Zabawka krecik("Ahoj");
		cout << "A: W sumie zabawek: " << ile_zabawek << endl;
	}
	cout << "B: W sumie zabawek: " << ile_zabawek << endl;
}