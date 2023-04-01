#pragma once
#include "arbore2.h";
#include <fstream>

/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule și un număr k.
În arbore rădăcina se află pe nivelul 0, fii rădăcinii pe nivelul 1,
fii fiilor rădăcinii pe nivelul 2, etc. Să se determine suma valorilor din nodurile aflate pe nivelul k.*/


void citireVector(int v[], int& n) {

	ifstream f("biarbore.in");
	n = 0;
	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}


void sol760() {

	int v[100], n;

	citireVector(v, n);

	BinaryTree tree;


}