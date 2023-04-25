#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Podopieczni.h"

using namespace std;

// Konstruktor i destruktor
Podopieczny::Podopieczny() {}
Podopieczny::~Podopieczny() {}

// Klasa
void Podopieczny::wpisz() {
    fstream plik;
    plik.open("podopieczni_lista.txt", ios::app);
    if (plik.good() == true) {
	    cout << endl << "DODAWANIE OSOBY" << endl;
	    cout << "Imie: ";
	    getline(cin, imie);
	    cout << "Nazwisko: ";
	    getline(cin, nazwisko);
	    cout << "Cena za zajecia: ";
	    cin >> cena_za_zajecia;
	    cin.ignore();
        plik << imie << endl;
        plik << nazwisko << endl;
        plik << cena_za_zajecia << endl;
    } else {
        cout << "Blad odczytu pliku";
    }
    plik.close();
}
void Podopieczny::pokaz() {
	cout << imie << " " << nazwisko << " " << cena_za_zajecia << " zl" << endl;
}
void Podopieczny::zmien_cene(float c) {
	cena_za_zajecia = c;
}
string Podopieczny::podaj_imie() {
	return imie;
}
string Podopieczny::podaj_nazwisko() {
	return nazwisko;
}
float Podopieczny::podaj_cene() {
	return cena_za_zajecia;
}

// Kontener klasy vector
void Baza::dodaj() {
	char decyzja = 't';
	    while (decyzja == 't') {
		Podopieczny tmp_czlowiek;
		tmp_czlowiek.wpisz();
		lista.push_back(tmp_czlowiek);
		cout << "\nDodano nowa osobe!" << endl;
		cout << "Czy chcesz dodac nowa osobe? (t/n) ";
		cin >> decyzja;
		cin.ignore();
	};
}
void Baza::pokaz_liste() {
	cout << endl << "LISTA OSOB" << endl;
	for (unsigned int i = 0; i < lista.size(); i++) {
		cout << i + 1 << ". ";
		lista[i].pokaz();
	}
	cout << endl;
}
void Baza::usun() {
	unsigned int id;
	cout << endl << "USUWANIE REKORDU" << endl;
	cout << "Podaj numer ID: ";
	cin >> id;
	if (id > lista.size())
		throw runtime_error("Nie ma takiego rekordu");
	lista.erase(lista.begin() + (id-1));
	cout << "Usunieto uzytkownia o ID " << id << ". " << endl;
}
void Baza::wyszukaj_po_imieniu() {
	string imie;
	cin.ignore();
	cout << endl << "WYSZUKIWANIE PO IMIENIU" << endl;
	cout << "Podaj imie do wyszukania: ";
	getline(cin, imie);
	bool znaleziono = false;
	for (unsigned int i = 0; i < lista.size(); i++) {
		if (lista[i].podaj_imie() == imie) {
			lista[i].pokaz();
			znaleziono = true;
		}
	}
	if (!znaleziono) {
		cout << "Nie znaleziono" << endl;
	}
}
void Baza::wyszukaj_po_nazwisku() {
	string nazwisko;
	cin.ignore();
	cout << endl << "WYSZUKIWANIE PO IMIENIU" << endl;
	cout << "Podaj nazwisko do wyszukania: ";
	getline(cin, nazwisko);
	bool znaleziono = false;
	for (unsigned int i = 0; i < lista.size(); i++) {
		if (lista[i].podaj_nazwisko() == nazwisko) {
			lista[i].pokaz();
			znaleziono = true;
		}
	}
	if (!znaleziono) {
		cout << "Nie znaleziono" << endl;
	}
}
void Baza::zmien_cene() {
	unsigned int id;
	float nowa_cena;
	cout << endl << "ZMIANA CENY" << endl;
	cout << "Podaj numer ID: ";
	cin >> id;
	if (id > lista.size())
		throw runtime_error("Nie ma takiego rekordu");
	cout << "Nowa cena: ";
	cin >> nowa_cena;
	lista[id - 1].zmien_cene(nowa_cena);
}
