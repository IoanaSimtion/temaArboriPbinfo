#pragma once

#include "node.h";


template<typename C>
struct Coada {

	Node<C>* top = NULL;


	void afisare() {

		Node<C>* aux = top;

		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;

		}

	}


	void push(C data) {

		if (top == NULL) {

			top = new Node<C>();

			top->data = data;

			top->next = NULL;

		}
		else {

			Node<C>* nou = new Node<C>();

			Node<C>* aux = top;

			while (aux->next != NULL) {

				aux = aux->next;

			}

			aux->next = nou;

			nou->data = data;

			nou->next = NULL;

		}

	}


	void pop() {

		top = top->next;

	}


	bool isEmpty() {

		if (top == NULL) {

			return true;

		}

		return false;

	}


	Node<C>* peak() {



		return top;

	}

	Node<C>* iterator() {

		return this->top;

	}

};