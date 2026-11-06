#include <iostream>
using namespace std;

class ColaDinamica {
private:
	struct Nodo {
		int dato;
		Nodo* siguiente;
	};
	Nodo* frente;
	Nodo* fin;
public:
	ColaDinamica() {
		frente = nullptr;
		fin = nullptr;
	}
	
	~ColaDinamica() {
		int dato;
		while (desencolar(dato));
	}
	
	bool vacia() { return frente == nullptr; }
	
	void encolar(int dato) {
		Nodo* nuevo = new Nodo;
		nuevo->dato = dato;
		nuevo->siguiente = nullptr;
		if (vacia()) frente = nuevo;
		else         fin->siguiente = nuevo;
		fin = nuevo;
	}
	
	bool desencolar(int &dato) {
		if (vacia()) return false;
		Nodo* aux = frente;
		dato = aux->dato;
		frente = aux->siguiente;
		if (frente == nullptr) fin = nullptr;
		delete aux;
		return true;
	}
	
	bool primero(int &dato) {
		if (vacia()) return false;
		dato = frente->dato;
		return true;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La cola esta vacia\n";
			return;
		}
		cout << "Cola (del frente al final): ";
		Nodo* aux = frente;
		while (aux != nullptr) {
			cout << aux->dato << " ";
			aux = aux->siguiente;
		}
		cout << endl;
	}
};

int main() {
	ColaDinamica cola;
	int opcion, dato;
	
	cout << "--- Cola Dinamica POO ---\n";
	do {
		cout << "\n1.Encolar 2.Desencolar 3.Primero 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a encolar: ";
			cin >> dato;
			cola.encolar(dato);
			cout << "Dato encolado\n";
			break;
		case 2:
			if (cola.desencolar(dato)) cout << "Dato desencolado: " << dato << endl;
			else cout << "Cola vacia: no se puede desencolar\n";
			break;
		case 3:
			if (cola.primero(dato)) cout << "Primero: " << dato << endl;
			else cout << "Cola vacia\n";
			break;
		case 4:
			cola.mostrar();
			break;
		case 0:
			cout << "Fin del programa\n";
			break;
		default:
			cout << "Opcion invalida\n";
		}
	} while (opcion != 0);
	return 0;
}
