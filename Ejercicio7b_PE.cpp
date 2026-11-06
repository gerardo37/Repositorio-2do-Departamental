#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

struct Lista {
	Nodo* inicio;
	int cantidad;
};

void iniciar(Lista &l) {
	l.inicio = nullptr;
	l.cantidad = 0;
}

bool vacia(Lista &l) { return l.inicio == nullptr; }

bool insertar(Lista &l, int pos, int dato) {
	if (pos < 1 || pos > l.cantidad + 1) return false;
	Nodo* nuevo = new Nodo;
	nuevo->dato = dato;
	if (pos == 1) {
		nuevo->siguiente = l.inicio;
		l.inicio = nuevo;
	} else {
		Nodo* ant = l.inicio;
		for (int i = 1; i < pos - 1; i++) ant = ant->siguiente;
		nuevo->siguiente = ant->siguiente;
		ant->siguiente = nuevo;
	}
	l.cantidad++;
	return true;
}

bool eliminar(Lista &l, int pos, int &dato) {
	if (pos < 1 || pos > l.cantidad) return false;
	Nodo* aux;
	if (pos == 1) {
		aux = l.inicio;
		l.inicio = aux->siguiente;
	} else {
		Nodo* ant = l.inicio;
		for (int i = 1; i < pos - 1; i++) ant = ant->siguiente;
		aux = ant->siguiente;
		ant->siguiente = aux->siguiente;
	}
	dato = aux->dato;
	delete aux;
	l.cantidad--;
	return true;
}

int buscar(Lista &l, int dato) {
	Nodo* aux = l.inicio;
	int pos = 1;
	while (aux != nullptr) {
		if (aux->dato == dato) return pos;
		aux = aux->siguiente;
		pos++;
	}
	return 0;
}

void mostrar(Lista &l) {
	if (vacia(l)) {
		cout << "La lista esta vacia\n";
		return;
	}
	cout << "Lista: ";
	Nodo* aux = l.inicio;
	while (aux != nullptr) {
		cout << aux->dato << " ";
		aux = aux->siguiente;
	}
	cout << endl;
}

void liberar(Lista &l) {
	int dato;
	while (eliminar(l, 1, dato));
}

int main() {
	Lista lista;
	iniciar(lista);
	int opcion, dato, pos;
	
	cout << "--- Lista Dinamica PE ---\n";
	do {
		cout << "\n1.Insertar 2.Eliminar 3.Buscar 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Posicion (1 a " << lista.cantidad + 1 << "): ";
			cin >> pos;
			cout << "Dato a insertar: ";
			cin >> dato;
			if (insertar(lista, pos, dato)) cout << "Dato insertado\n";
			else cout << "Posicion invalida\n";
			break;
		case 2:
			cout << "Posicion a eliminar: ";
			cin >> pos;
			if (eliminar(lista, pos, dato)) cout << "Dato eliminado: " << dato << endl;
			else cout << "Lista vacia o posicion invalida\n";
			break;
		case 3:
			cout << "Dato a buscar: ";
			cin >> dato;
			pos = buscar(lista, dato);
			if (pos > 0) cout << "Dato " << dato << " encontrado en la posicion " << pos << endl;
			else cout << "Dato no encontrado\n";
			break;
		case 4:
			mostrar(lista);
			break;
		case 0:
			cout << "Fin del programa\n";
			break;
		default:
			cout << "Opcion invalida\n";
		}
	} while (opcion != 0);
	
	liberar(lista);
	return 0;
}
