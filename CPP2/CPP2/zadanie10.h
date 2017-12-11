#pragma once
void zadanie10(void);
void wczytaj_z_pliku(std::string sciezkadopliku, struct osoba_t **wosoba);
void dodaj_element_do_listy(struct osoba_t ** wosoba);
int przenies_z_listy_do_tablicy(struct osoba_t **wosoba, struct osobatab_t **wosobatab, int ilosc_elementow, std::string nazwisko);
void wypisz_liste_i_tablice(struct osoba_t **wosoba, struct osobatab_t **wosobatab, int liczba_elementow);
int usun_element_z_tablicy(struct osobatab_t **wosobatab, int liczbaelementow, std::string nazwisko);
int konwertuj_liste_na_tablice(struct osoba_t **wosoba, struct osobatab_t **wosobatab);
void posprzataj_pamiec(struct osoba_t **wosoba, struct osobatab_t **wosobatab);
