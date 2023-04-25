#include<iostream>
#include "Podopieczni.h"

using namespace std;

int main() {
	try {
		Baza b;
		b.dodaj();
		b.pokaz_liste();
		b.usun();
		b.pokaz_liste();
		b.wyszukaj_po_imieniu();
		b.wyszukaj_po_nazwisku();
		b.zmien_cene();
		b.pokaz_liste();
	}
	catch (runtime_error& e) {
		cout << "Blad " << e.what();
	}
}