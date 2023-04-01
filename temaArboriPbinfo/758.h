#pragma once
#include "arbore2.h";
#include <fstream>


/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule.
Să se determine cele mai mici valori număr prim din subarborii stâng și drept ai rădăcinii.*/


void citireVector(int v[], int& n) {

	ifstream f("biminprim.in");
	n = 0;
	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}


void sol758() {

	int v[100], n, minSt = INT_MAX, minDr = INT_MAX;

	citireVector(v, n);

	BinaryTree tree;

	tree.addPreordine(v, n);

	tree.minimSubarboreDr(minDr, tree.root->right);

	tree.minimSubarboreSt(minSt, tree.root->left);

	if (minSt > 1000) {
		cout << -1 << ' ';
	}
	else {
		cout << minSt << ' ';
	}
	if (minDr > 1000) {
		cout << -1 << ' ';
	}
	else {
		cout << minDr << ' ';
	}

}