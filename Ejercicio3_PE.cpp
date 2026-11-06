#include <iostream>
using namespace std;

const int MAX = 5;

struct Pila {
	int datos[MAX];
	int tope;
};

void iniciar(Pila &p) { p.tope = -1; }
bool vacia(Pila &p)   { return p.tope == -1; }
bool llena(Pila &p)   { return p.tope == MAX - 1; }

bool push(Pila &p, int dato) {
	if (llena(p)) return false;
	p.datos[++p.tope] = dato;
	return true;
}

bool pop(Pila &p, int &dato) {
	if (vacia(p)) return false;
	dato = p.datos[p.tope--];
	return true;
}

bool cima(Pila &p, int &dato) {
	if (vacia(p)) return false;
	dato = p.datos[p.tope];
	return true;
}

void mostrar(Pila &p) {
	if (vacia(p)) {
		cout << "La pila esta vacia\n";
		return;
	}
	cout << "Pila (de la cima a la base): ";
	for (int i = p.tope; i >= 0; i--) cout << p.datos[i] << " ";
	cout << endl;
}

int main() {
	Pila pila;
	iniciar(pila);
	int opcion, dato;
	
	cout << "--- Pila Estatica PE (capacidad " << MAX << ") ---\n";
	do {
		cout << "\n1.Push 2.Pop 3.Cima 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a apilar: ";
			cin >> dato;
			if (push(pila, dato)) cout << "Dato apilado\n";
			else cout << "Pila llena: no se puede apilar\n";
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
	return 0;
}
