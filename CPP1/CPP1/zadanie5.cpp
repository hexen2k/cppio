#include "zadanie5.h"

void zadanie5(void) {
	int liczba_desek = 0;
	int ostatnia_pusta_deska = 0;
	int dlugosc_skoku = 0;
	static int deska[1000];

	cout << "Podaj liczbe desek mostu: ";
	cin >> liczba_desek;
	cout << "Podaj rozlozenie pinezek na deskach mostu (0 brak, 1 obecna) np. 0 0 1 1 0 1 0...:" << endl;
	for (int i = 1; i <= liczba_desek; i++) {
		cin >> deska[i];
		if (deska[i] == 0) {
			ostatnia_pusta_deska = i;
		}
		if (deska[i] && ostatnia_pusta_deska < i) {
			if (dlugosc_skoku < i - ostatnia_pusta_deska) {
				dlugosc_skoku = i - ostatnia_pusta_deska;
			}
		}
	}
	cout << "Wymagana dlugosc skoku Jasia: " << dlugosc_skoku;
}