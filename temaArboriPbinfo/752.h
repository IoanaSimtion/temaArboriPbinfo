#pragma once
#include "arbore2.h";
#include <fstream>


/*Se consideră un arbore binar în care nodurile memorează numere naturale nenule. 
Să se determine valorile memorate în descendenții direcți ai rădăcinii arborelui.*/



void citireVector(int v[], int& n) {

	ifstream f("biarbore.in");
	n = 0;
	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}


void sol752() {

	int v[100], n;

	citireVector(v, n);

	BinaryTree tree;

	tree.addPreordine(v, n);

	cout << tree.root->left->data << ' ' << tree.root->right->data;

}