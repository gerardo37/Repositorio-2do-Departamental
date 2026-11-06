#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

bool insertar(list<int> &l, int pos, int dato) {
	if (pos < 1 || pos > (int)l.size() + 1) return false;
	list<int>::iterator it = l.begin();
	advance(it, pos - 1);
	l.insert(it, dato);
	return true;
}

bool eliminar(list<int> &l, int pos, int &dato) {
	if (pos < 1 || pos > (int)l.size()) return false;
	list<int>::iterator it = l.begin();
	advance(it, pos - 1);
	dato = *it;
	l.erase(it);
	return true;
}

int buscar(list<int> &l, int dato) {
	list<int>::iterator it = find(l.begin(), l.end(), dato);
	if (it == l.end()) return 0;
	return distance(l.begin(), it) + 1;
}

void mostrar(list<int> &l) {
	if (l.empty()) {
		cout << "La lista esta vacia\n";
		return;
	}
	cout << "Lista: ";
	for (int x : l) cout << x << " ";
	cout << endl;
}

int main() {
	list<int> lista;
	int opcion, dato, pos;
	
	cout << "--- Lista Dinamica con Libreria PE ---\n";
	do {
		cout << "\n1.Insertar 2.Eliminar 3.Buscar 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Posicion (1 a " << lista.size() + 1 << "): ";
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
	return 0;
}
