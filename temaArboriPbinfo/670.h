#pragma once
#include "arbore.h";
#include <fstream>


/*Considerăm un arbore binar cu n noduri în care fiecare nod este numerotat de la 1 la n
și conține o valoare număr natural. Să se afișeze valorile din arbore în urma
parcurgerii în preordine (rădăcină, stâng, drept).*/


//todo functie ce memoreaza datele in matrice

void treeMatrice(int m[100][100], int d, int& n) {

	ifstream f("preordine.in");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			f >> m[i][j];
		}
	}

}


//todo functie ce afiseaza o matrice

void afisareMatrice(int m[100][100], int n, int d) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}

}

//todo functie ce verifica daca un nr se gaseste in matrice

bool exista(int m[100][100], int n, int d, int data) {

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < d; j++) {
			if (m[i][j] == data) {
				return true;
			}
		}
	}

	return false;

}


//todo functie ce returneaza valoarea root ului

int treeRoot(int m[100][100], int n, int d) {

	for (int i = 0; i < n; i++) {
		if (!exista(m, n, d, i + 1)) {
			return m[i][0];
		}
	}

}


//tood functie ce returneaza indicele root ului

int pozRoot(int m[100][100], int n, int d, int root) {

	for (int i = 0; i < n; i++) {
		if (m[i][0] == root) {
			return i;
		}
	}

}


void sol670() {

	int m[100][100], d = 3, n, root, parinte;

	treeMatrice(m, d, n);

	afisareMatrice(m, n, d);

	root = treeRoot(m, n, d);

	BinaryTree tree;

	tree.add(m, n, d, pozRoot(m, n, d, root));

	tree.preordine(tree.root);

}