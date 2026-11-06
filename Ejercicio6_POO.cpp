#include <iostream>
using namespace std;

class PilaDinamica {
private:
	struct Nodo {
		int dato;
		Nodo* siguiente;
	};
	Nodo* tope;
public:
	PilaDinamica() { tope = nullptr; }
	
	~PilaDinamica() {
		int dato;
		while (pop(dato));
	}
	
	bool vacia() { return tope == nullptr; }
	
	void push(int dato) {
		Nodo* nuevo = new Nodo;
		nuevo->dato = dato;
		nuevo->siguiente = tope;
		tope = nuevo;
	}
	
	bool pop(int &dato) {
		if (vacia()) return false;
		Nodo* aux = tope;
		dato = aux->dato;
		tope = aux->siguiente;
		delete aux;
		return true;
	}
	
	bool cima(int &dato) {
		if (vacia()) return false;
		dato = tope->dato;
		return true;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La pila esta vacia\n";
			return;
		}
		cout << "Pila (de la cima a la base): ";
		Nodo* aux = tope;
		while (aux != nullptr) {
			cout << aux->dato << " ";
			aux = aux->siguiente;
		}
		cout << endl;
	}
};

int main() {
	PilaDinamica pila;
	int opcion, dato;
	
	cout << "--- Pila Dinamica POO ---\n";
	do {
		cout << "\n1.Push 2.Pop 3.Cima 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a apilar: ";
			cin >> dato;
			pila.push(dato);
			cout << "Dato apilado\n";
			break;
		case 2:
			if (pila.pop(dato)) cout << "Dato desapilado: " << dato << endl;
			else cout << "Pila vacia: no se puede desapilar\n";
			break;
		case 3:
			if (pila.cima(dato)) cout << "Cima: " << dato << endl;
			else cout << "Pila vacia\n";
			break;
		case 4:
			pila.mostrar();
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
