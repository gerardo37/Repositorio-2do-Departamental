#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

struct Cola {
	Nodo* frente;
	Nodo* fin;
};

void iniciar(Cola &c) {
	c.frente = nullptr;
	c.fin = nullptr;
}

bool vacia(Cola &c) { return c.frente == nullptr; }

void encolar(Cola &c, int dato) {
	Nodo* nuevo = new Nodo;
	nuevo->dato = dato;
	nuevo->siguiente = nullptr;
	if (vacia(c)) c.frente = nuevo;
	else          c.fin->siguiente = nuevo;
	c.fin = nuevo;
}

bool desencolar(Cola &c, int &dato) {
	if (vacia(c)) return false;
	Nodo* aux = c.frente;
	dato = aux->dato;
	c.frente = aux->siguiente;
	if (c.frente == nullptr) c.fin = nullptr;
	delete aux;
	return true;
}

bool primero(Cola &c, int &dato) {
	if (vacia(c)) return false;
	dato = c.frente->dato;
	return true;
}

void mostrar(Cola &c) {
	if (vacia(c)) {
		cout << "La cola esta vacia\n";
		return;
	}
	cout << "Cola (del frente al final): ";
	Nodo* aux = c.frente;
	while (aux != nullptr) {
		cout << aux->dato << " ";
		aux = aux->siguiente;
	}
	cout << endl;
}

void liberar(Cola &c) {
	int dato;
	while (desencolar(c, dato));
}

int main() {
	Cola cola;
	iniciar(cola);
	int opcion, dato;
	
	cout << "--- Cola Dinamica PE ---\n";
	do {
		cout << "\n1.Encolar 2.Desencolar 3.Primero 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a encolar: ";
			cin >> dato;
			encolar(cola, dato);
			cout << "Dato encolado\n";
			break;
		case 2:
			if (desencolar(cola, dato)) cout << "Dato desencolado: " << dato << endl;
			else cout << "Cola vacia: no se puede desencolar\n";
			break;
		case 3:
			if (primero(cola, dato)) cout << "Primero: " << dato << endl;
			else cout << "Cola vacia\n";
			break;
		case 4:
			mostrar(cola);
			break;
		case 0:
			cout << "Fin del programa\n";
			break;
		default:
			cout << "Opcion invalida\n";
		}
	} while (opcion != 0);
	
	liberar(cola);
	return 0;
}
