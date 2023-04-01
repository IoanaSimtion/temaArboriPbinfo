#pragma once
#include "arbore2.h";
#include <fstream>

/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule.
Să se afișeze valorile memorate în nodurile neterminale ale arborelui, în ordine descrescătoare.*/



void citireVector(int v[], int& n) {

	ifstream f("biarbore.in");
	n = 0;

	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


void bubbleSort(int v[], int n) {

	bool flag = 0;

	do {

		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] < v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				flag = 0;
			}
		}

	} while (flag == 0);


}



void sol792() {

	int v[100], n, noduriNeterminale[50], d = 0;

	citireVector(v, n);

	BinaryTree tree;

	tree.addPreordine(v, n);

	tree.memorareNoduriNeterminale(noduriNeterminale, d, tree.root);

	bubbleSort(noduriNeterminale, d);

	afisareVector(noduriNeterminale, d);

}