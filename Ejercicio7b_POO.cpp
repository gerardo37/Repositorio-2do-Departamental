#include <iostream>
using namespace std;

class ListaDinamica {
private:
	struct Nodo {
		int dato;
		Nodo* siguiente;
	};
	Nodo* inicio;
	int cantidad;
public:
	ListaDinamica() {
		inicio = nullptr;
		cantidad = 0;
	}
	
	~ListaDinamica() {
		int dato;
		while (eliminar(1, dato));
	}
	
	int getCantidad() { return cantidad; }
	bool vacia()      { return inicio == nullptr; }
	
	bool insertar(int pos, int dato) {
		if (pos < 1 || pos > cantidad + 1) return false;
		Nodo* nuevo = new Nodo;
		nuevo->dato = dato;
		if (pos == 1) {
			nuevo->siguiente = inicio;
			inicio = nuevo;
		} else {
			Nodo* ant = inicio;
			for (int i = 1; i < pos - 1; i++) ant = ant->siguiente;
			nuevo->siguiente = ant->siguiente;
			ant->siguiente = nuevo;
		}
		cantidad++;
		return true;
	}
	
	bool eliminar(int pos, int &dato) {
		if (pos < 1 || pos > cantidad) return false;
		Nodo* aux;
		if (pos == 1) {
			aux = inicio;
			inicio = aux->siguiente;
		} else {
			Nodo* ant = inicio;
			for (int i = 1; i < pos - 1; i++) ant = ant->siguiente;
			aux = ant->siguiente;
			ant->siguiente = aux->siguiente;
		}
		dato = aux->dato;
		delete aux;
		cantidad--;
		return true;
	}
	
	int buscar(int dato) {
		Nodo* aux = inicio;
		int pos = 1;
		while (aux != nullptr) {
			if (aux->dato == dato) return pos;
			aux = aux->siguiente;
			pos++;
		}
		return 0;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La lista esta vacia\n";
			return;
		}
		cout << "Lista: ";
		Nodo* aux = inicio;
		while (aux != nullptr) {
			cout << aux->dato << " ";
			aux = aux->siguiente;
		}
		cout << endl;
	}
};

int main() {
	ListaDinamica lista;
	int opcion, dato, pos;
	
	cout << "--- Lista Dinamica POO ---\n";
	do {
		cout << "\n1.Insertar 2.Eliminar 3.Buscar 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Posicion (1 a " << lista.getCantidad() + 1 << "): ";
			cin >> pos;
			cout << "Dato a insertar: ";
			cin >> dato;
			if (lista.insertar(pos, dato)) cout << "Dato insertado\n";
			else cout << "Posicion invalida\n";
			break;
		case 2:
			cout << "Posicion a eliminar: ";
			cin >> pos;
			if (lista.eliminar(pos, dato)) cout << "Dato eliminado: " << dato << endl;
			else cout << "Lista vacia o posicion invalida\n";
			break;
		case 3:
			cout << "Dato a buscar: ";
			cin >> dato;
			pos = lista.buscar(dato);
			if (pos > 0) cout << "Dato " << dato << " encontrado en la posicion " << pos << endl;
			else cout << "Dato no encontrado\n";
			break;
		case 4:
			lista.mostrar();
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
