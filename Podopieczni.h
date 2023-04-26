#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Podopieczny {
	string imie;
	string nazwisko;
	float cena_za_zajecia{};
public:
	Podopieczny();
	~Podopieczny();

	void wpisz();
	void pokaz();
	void zmien_cene(float);

    string podaj_imie();
	string podaj_nazwisko();
	float podaj_cene();
};

class Baza {
	vector<Podopieczny> lista;
public:
    void wczytaj();
	void dodaj();
	void usun();
	void pokaz_liste();
	void wyszukaj_po_imieniu();
	void wyszukaj_po_nazwisku();
	void zmien_cene();
};