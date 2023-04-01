#pragma once
#include "arbore2.h";
#include <fstream>

/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule și un număr k.
În arbore rădăcina se află pe nivelul 0, fii rădăcinii pe nivelul 1,
fii fiilor rădăcinii pe nivelul 2, etc. Să se determine suma valorilor din nodurile aflate pe nivelul k.*/


void citireVector(int v[], int& n) {

	ifstream f("knivel.in");
	n = 0;
	while (!f.eof()) {
		f >> v[n];
		n++;
	}


}


void sol760() {

	int v[100], n, k, suma = 0;

	citireVector(v, n);
	
	cout << "k=";
	cin >> k;

	BinaryTree tree;

	tree.addPreordine(v, n);

	tree.sumaNivel(suma, k);

	cout << "Elementele de pe nivelul " << k << " sunt: ";

	tree.afisareElemNivel(k);
	
	cout << "Suma nivel " << k << ": " << suma;

}