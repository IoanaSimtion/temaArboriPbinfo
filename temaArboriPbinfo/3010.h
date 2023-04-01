#pragma once
#include "arbore2.h";
#include <fstream>

/*Un arbore binar de căutare (BST – Binary Search Tree) este un arbore binar cu proprietatea 
că valoarea memorată într-un nod este mai mare decât valoarea memorată în orice nod din subarborele 
său stâng și este mai mică sau egală decât valoarea memorată în orice nod din subarborele său drept.*/



void citireVector(int v[], int& n) {

	ifstream f("biarbore.in");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void sol3010() {

	int v[100], n;

	citireVector(v, n);

	BinaryTree tree;

	for (int i = 0; i < n; i++) {
		tree.addClasic(tree.root, v[i]);
	}

	tree.afisare();

}