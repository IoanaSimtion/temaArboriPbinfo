#include "treeNode.h";

#include "stiva.h";

#include "coada.h";

#include <fstream>

#include <math.h>

#pragma once

struct BinaryTree {

	TreeNode* root = NULL;

	BinaryTree() {

	}

	TreeNode* find(TreeNode* current) {

		if (current == NULL) {
			return current;
		}

		TreeNode* aux = find(current->left);

		if (aux == NULL) {
			return aux;
		}

		return find(current->right);
	}



	//ADD



	void addClasic(TreeNode* current, int data) {

		if (current == NULL) {
			TreeNode* nou = new TreeNode();
			nou->left = NULL;
			nou->right = NULL;
			nou->data = data;
		}
		else {
			if (current->data > data) {
				if (current->left != NULL) {
					addClasic(current->left, data);
				}
				else {
					current->left = new TreeNode();
					current->left->data = data;
					current->left->left = NULL;
					current->left->right = NULL;
				}
			}
			else {
				if (current->right != NULL) {
					addClasic(current->right, data);
				}
				else {
					current->right = new TreeNode();
					current->right->data = data;
					current->right->left = NULL;
					current->right->right = NULL;
				}
			}
		}

	}


	TreeNode* addData(TreeNode* current, int data) {


		if (current->data == 0) {

			return NULL;
		}

		if (current->left == NULL) {
			TreeNode* aux = new TreeNode();
			aux->data = data;
			aux->left = NULL;
			aux->right = NULL;
			current->left = aux;
			return aux;
		}

		TreeNode* left = addData(current->left, data);

		if (left == NULL) {

			if (current->right == NULL) {
				TreeNode* aux = new TreeNode();
				aux->data = data;
				aux->left = NULL;
				aux->right = NULL;
				current->right = aux;
				return aux;
			}
			return addData(current->right, data);

		}
		return left;
	}

	void addPreordine(int v[], int n) {

		root = new TreeNode();

		root->data = v[0];

		TreeNode* current = root;

		for (int i = 1; i < n; i++) {
			addData(current, v[i]);
		}

	}


	//AFISARE



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

			if (aux->data != 0) {
				cout << aux->data << ' ';
			}

			c.pop();
		}

	}


	void afisarePreordineStanga(TreeNode* current) {

		if (current == NULL || current->data == 0) {
			return;
		}

		cout << current->data << ' ';
		afisarePreordineStanga(current->left);
		afisarePreordineStanga(current->right);

	}


	void afisareInordine(TreeNode* current) {

		if (current == NULL || current->data == 0) {
			return;
		}

		afisareInordine(current->left);
		cout << current->data << ' ';
		afisareInordine(current->right);

	}


	void afisarePostordine(TreeNode* current) {

		if (current == NULL || current->data == 0) {
			return;
		}

		afisarePostordine(current->left);
		afisarePostordine(current->right);
		cout << current->data << ' ';

	}


	void sumaNivel(int& suma, int k) {

		TreeNode* aux = root;
		Coada<TreeNode*> c;

		c.push(aux);

		int ct = 0;

		while (!c.isEmpty()) {

			aux = c.peak()->data;

			if (aux->left != NULL) {
				c.push(aux->left);
			}

			if (aux->right != NULL) {
				c.push(aux->right);
			}

			/*if (aux->data != 0) {
				cout << aux->data << ' ';
				cout << ct << endl;
			}*/


			if ((ct >= pow(2, k) - 1) && (ct < pow(2, k + 1) - 1)) {
				suma += aux->data;
				//cout << "aici" << endl;
			}
			
			ct++;
			c.pop();
		}

	}



	//ALTE FUNCTII


	//todo functie ce afiseaza elementele de pe un nivel

	void afisareElemNivel(int k) {

		TreeNode* aux = root;

		Coada<TreeNode*> c;

		c.push(aux);

		int ct = 0;

		while (!c.isEmpty()) {

			aux = c.peak()->data;

			if (aux->left != NULL) {
				c.push(aux->left);
			}

			if (aux->right != NULL) {
				c.push(aux->right);
			}

			if (ct >= pow(2, k) - 1 && ct < pow(2, k + 1) - 1) {
				cout << aux->data << ' ';
			}

			ct++;

			c.pop();

		}
		cout << endl;

	}


	//todo functie ce verifica daca un nr este prim

	bool ePrim(int nr) {

		for (int i = 2; i < sqrt(nr); i++) {
			if (nr % i == 0) {
				return false;
			}
		}
		return true;

	}

	//todo functie ce afla cel mai mic nr prim din subarborele stang

	void minimSubarboreSt(int& min, TreeNode* current) {

		if (current == NULL) {
			return;
		}

		minimSubarboreSt(min, current->left);
		if (current->data < min && ePrim(current->data) && current->data!=0) {
			min = current->data;
		}
		minimSubarboreSt(min, current->right);

		if (current == root) {
			return;
		}

	}

	//todo functie ce afla cel mai mic nr prim din subarborele drept

	void minimSubarboreDr(int& min, TreeNode* current) {

		if (current == NULL) {
			return;
		}

		minimSubarboreDr(min, current->right);
		if (current->data < min && ePrim(current->data) && current->data != 0){
			min = current->data;
		}
		minimSubarboreDr(min, current->left);

		if (current == root) {
			return;
		}
	}
	

	//todo funtie ce memoreaza intr un vector nodurile terminale

	void memorareNoduri(int v[], int& n, TreeNode* current) {

		if (current == NULL || current->data == 0) {
			return;
		}
		if (current->left->data == 0 && current->right->data == 0) {
			v[n] = current->data;
			n++;
		}
		memorareNoduri(v, n, current->left);
		memorareNoduri(v, n, current->right);

	}

	void memorareNoduriNeterminale(int v[], int& n, TreeNode* current) {

		if (current == NULL || current->data == 0) {
			return;
		}
		if (current->left->data != 0 && current->right->data != 0) {
			v[n] = current->data;
			n++;
		}
		memorareNoduriNeterminale(v, n, current->left);
		memorareNoduriNeterminale(v, n, current->right);

	}

	//todo functie ce returneaza nr de noduri cu un singur descendent

	void ctNoduri(TreeNode* current, int& ct) {

		if (current == NULL || current->data == 0) {
			return;
		}

		if (current->left->data == 0 && current->right->data != 0 || current->left->data != 0 && current->right->data == 0) {
			ct++;
		}

		ctNoduri(current->left, ct);
		ctNoduri(current->right, ct);
	}


	//tood functie ce returneaza maximul din subarborele stang

	void maxSubarboreStang(int& max, TreeNode* current) {

		if (current == NULL) {
			return;
		}

		maxSubarboreStang(max, current->left);
		if (current->data > max) {
			max = current->data;
		}
		maxSubarboreStang(max, current->right);

		if (current == root) {
			return;
		}

	}


	//todo functie ce returneaza maximul din subarborele drept

	void maxSubarboreDrept(int& max, TreeNode* current) {

		if (current == NULL) {
			return;
		}

		maxSubarboreDrept(max, current->right);
		if (current->data > max) {
			max = current->data;
		}
		maxSubarboreDrept(max, current->left);

		if (current == root) {
			return;
		}
	}

};
