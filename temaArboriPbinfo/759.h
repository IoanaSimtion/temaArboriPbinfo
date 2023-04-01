#pragma once
#include "arbore2.h";
#include <fstream>

/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule.
Să se afișeze valorile din arbore în urma parcurgerii în lățime, pornind din rădăcină.*/



void citireVector(int v[], int& n) {

	ifstream f("biarbore.in");
	n = 0;

	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}



void sol759() {

	int v[100], n;

	citireVector(v, n);

	BinaryTree tree;

	tree.addPreordine(v, n);

	tree.afisare();

}