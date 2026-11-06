#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

struct Pila {
	Nodo* tope;
};

void iniciar(Pila &p) { p.tope = nullptr; }
bool vacia(Pila &p)   { return p.tope == nullptr; }

void push(Pila &p, int dato) {
	Nodo* nuevo = new Nodo;
	nuevo->dato = dato;
	nuevo->siguiente = p.tope;
	p.tope = nuevo;
}

bool pop(Pila &p, int &dato) {
	if (vacia(p)) return false;
	Nodo* aux = p.tope;
	dato = aux->dato;
	p.tope = aux->siguiente;
	delete aux;
	return true;
}

bool cima(Pila &p, int &dato) {
	if (vacia(p)) return false;
	dato = p.tope->dato;
	return true;
}

void mostrar(Pila &p) {
	if (vacia(p)) {
		cout << "La pila esta vacia\n";
		return;
	}
	cout << "Pila (de la cima a la base): ";
	Nodo* aux = p.tope;
	while (aux != nullptr) {
		cout << aux->dato << " ";
		aux = aux->siguiente;
	}
	cout << endl;
}

void liberar(Pila &p) {
	int dato;
	while (pop(p, dato));
}

int main() {
	Pila pila;
	iniciar(pila);
	int opcion, dato;
	
	cout << "--- Pila Dinamica PE ---\n";
	do {
		cout << "\n1.Push 2.Pop 3.Cima 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a apilar: ";
			cin >> dato;
			push(pila, dato);
			cout << "Dato apilado\n";
			break;
		case 2:
			if (pop(pila, dato)) cout << "Dato desapilado: " << dato << endl;
			else cout << "Pila vacia: no se puede desapilar\n";
			break;
		case 3:
			if (cima(pila, dato)) cout << "Cima: " << dato << endl;
			else cout << "Pila vacia\n";
			break;
		case 4:
			mostrar(pila);
			break;
		case 0:
			cout << "Fin del programa\n";
			break;
		default:
			cout << "Opcion invalida\n";
		}
	} while (opcion != 0);
	
	liberar(pila);
	return 0;
}
