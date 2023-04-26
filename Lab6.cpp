#include <iostream>
#include "Podopieczni.h"

using namespace std;

int main()
{
	try
	{
		Baza b;
		//		b.dodaj();
		b.wczytaj();
		b.pokaz_liste_z_kontenera();
		//		b.usun();
		//		b.pokaz_liste();
		//		b.wyszukaj_po_imieniu();
		//		b.wyszukaj_po_nazwisku();
		//		b.zmien_cene();
		//		b.pokaz_liste();
		system("pause");
	}
	catch (runtime_error &e)
	{
		cout << "Blad " << e.what();
	}
}