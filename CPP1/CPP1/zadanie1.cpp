#include "zadanie1.h"

void zadanie1(void) {

    int wysokosc_jacka, wysokosc_wymagana, wysokosc_guza;
    cout << "Podaj wysokosc Jacka, wymagana wysokosc, oraz wartosc powiekszania sie guza: " << endl;
    cin >> wysokosc_jacka;
    cin >> wysokosc_wymagana;
    cin >> wysokosc_guza;

    if (wysokosc_wymagana > wysokosc_jacka){
        if ((wysokosc_wymagana-wysokosc_jacka)%wysokosc_guza){
            cout << (wysokosc_wymagana-wysokosc_jacka)/wysokosc_guza + 1;
        }
        else{
            cout << (wysokosc_wymagana-wysokosc_jacka)/wysokosc_guza;
        }
    }
    else{
        cout << 0;
    }
}
