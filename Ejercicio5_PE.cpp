#include <iostream>
using namespace std;

const int MAX = 5;

struct Lista {
	int datos[MAX];
	int cantidad;
};

void iniciar(Lista &l) { l.cantidad = 0; }
bool vacia(Lista &l)   { return l.cantidad == 0; }
bool llena(Lista &l)   { return l.cantidad == MAX; }

bool insertar(Lista &l, int pos, int dato) {
	if (llena(l) || pos < 1 || pos > l.cantidad + 1) return false;
	for (int i = l.cantidad; i >= pos; i--) l.datos[i] = l.datos[i - 1];
	l.datos[pos - 1] = dato;
	l.cantidad++;
	return true;
}

bool eliminar(Lista &l, int pos, int &dato) {
	if (pos < 1 || pos > l.cantidad) return false;
	dato = l.datos[pos - 1];
	for (int i = pos - 1; i < l.cantidad - 1; i++) l.datos[i] = l.datos[i + 1];
	l.cantidad--;
	return true;
}

int buscar(Lista &l, int dato) {
	for (int i = 0; i < l.cantidad; i++)
		if (l.datos[i] == dato) return i + 1;
	return 0;
}

void mostrar(Lista &l) {
	if (vacia(l)) {
		cout << "La lista esta vacia\n";
		return;
	}
	cout << "Lista: ";
	for (int i = 0; i < l.cantidad; i++) cout << l.datos[i] << " ";
	cout << endl;
}

int main() {
	Lista lista;
	iniciar(lista);
	int opcion, dato, pos;
	
	cout << "--- Lista Estatica PE (capacidad " << MAX << ") ---\n";
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
			else cout << "Lista llena o posicion invalida\n";
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
	return 0;
}
