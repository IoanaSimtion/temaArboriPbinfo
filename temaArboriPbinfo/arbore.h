#include "treeNode.h";

#include "stiva.h";

#include "coada.h";

#pragma once


struct BinaryTree {

	TreeNode* root = NULL;

	BinaryTree() {

	}



	//ADD


	//todo functie ce returneaza pozitia unui nr

	int pozNumar(int m[100][100], int n, int nr) {

		for (int i = 0; i < n; i++) {
			if (m[i][0] == nr) {
				return i;
			}
		}

	}

	//todo functie ce returneaza parintele

	int parinteNr(int m[100][100], int n, int nr) {
		int pozNr = pozNumar(m, n, nr);

		for (int i = 0; i < n; i++) {
			if (m[i][1] - 1 == pozNr || m[i][2] - 1 == pozNr) {
				return m[i][0];
			}
		}

		return -1;

	}

	TreeNode* find(int data, TreeNode* current) {

		if (current == NULL) {
			return NULL;
		}

		if (current->data == data) {
			return current;
		}

		TreeNode* left = find(data, current->left);

		if (left != NULL) {
			return left;
		}

		return find(data, current->right);

	}

	void addDupaParinte(TreeNode* parinte, int data) {

		if (parinte != NULL) {
			TreeNode* nou = new TreeNode();
			nou->left = NULL;
			nou->right = NULL;
			nou->data = data;

			if (parinte->left == NULL) {
				parinte->left = nou;
			}
			else {
				if (parinte->right == NULL) {
					parinte->right = nou;
				}
			}
		}
	}

	void add(int m[100][100], int n, int d, int pozRoot) {

		root = new TreeNode();

		Coada<int> c;

		c.push(m[pozRoot][1]);

		c.push(m[pozRoot][2]);

		root->data = m[pozRoot][0];

		int j = 0;

		while (j < n) {

			int indice = c.peak()->data - 1;

			c.pop();

			int par = parinteNr(m, n, m[indice][0]);

			if (par == -1) {

				addDupaParinte(root, m[indice][0]);

			}
			else {

				TreeNode* parent = find(par, root);


				addDupaParinte(parent, m[indice][0]);

			}

			//cream un treenode si adaugam pe stanga daca este liber daca nu pe dreapta

			c.push(m[indice][1]);
			c.push(m[indice][2]);

			j++;
		}

	}



	//AFISARI


	void afisare() {

		TreeNode* aux = root;
		Coada<TreeNode*> c;
		c.push(aux);

		while (!c.isEmpty()) {
			aux = c.peak()->data;

			if (aux->left != NULL) {
				c.push(aux->left);
			}
			if (aux->right != NULL) {
				c.push(aux->right);
			}

			cout << aux->data << ' ';

			c.pop();
		}

	}

	void preordine(TreeNode* current) {

		if (current == NULL) {
			return;
		}

		cout << current->data << ' ';
		preordine(current->left);
		preordine(current->right);

	}

	void inordine(TreeNode* current) {

		if (current == NULL) {
			return;
		}

		inordine(current->left);
		cout << current->data << ' ';
		inordine(current->right);
	}

	void postordine(TreeNode* current) {

		if (current == NULL) {
			return;
		}

		postordine(current->left);
		postordine(current->right);
		cout << current->data << ' ';

	}



	//ALTE FUNCTII


	//todo functie ce calculeaza suma nr din subarborele stang

	void sumaLeft(TreeNode* current, int& suma) {

		if (current == NULL) {
			return;
		}

		sumaLeft(current->left, suma);
		suma += current->data;
		sumaLeft(current->right, suma);

		if (current == root) {
			return;
		}

	}

	void sumaRight(TreeNode* current, int& suma) {

		if (current == NULL) {
			return;
		}

		sumaRight(current->right, suma);
		suma += current->data;
		sumaRight(current->left, suma);

		if (current == root) {
			return;
		}

	}

};