#pragma once
#include "arbore2.h";
#include <fstream>

/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule. Să se determine înălțimea arborelui.

Înălțimea unui arbore este egală cu numărul de noduri de pe cel mai lung lanț elementar care unește rădăcina cu un nod terminal.*/


void citireVector(int v[], int& n) {

	ifstream f("biarbore.in");
	n = 0;
	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}


int inaltimeArbore(int v[], int n) {

	int max = 0, ct = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] != 0) {
			ct++;
			if (ct > max) {
				max = ct;
			}
		}
		else {
			ct = 0;
		}
	}
	return max;
}

void sol761() {

	int v[100], n;

	citireVector(v, n);

	cout << inaltimeArbore(v, n);



}