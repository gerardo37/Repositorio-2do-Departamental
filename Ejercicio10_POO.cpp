#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

class ListaLibreria {
private:
	list<int> lista;
public:
	int getCantidad() { return (int)lista.size(); }
	bool vacia()      { return lista.empty(); }
	
	bool insertar(int pos, int dato) {
		if (pos < 1 || pos > getCantidad() + 1) return false;
		list<int>::iterator it = lista.begin();
		advance(it, pos - 1);
		lista.insert(it, dato);
		return true;
	}
	
	bool eliminar(int pos, int &dato) {
		if (pos < 1 || pos > getCantidad()) return false;
		list<int>::iterator it = lista.begin();
		advance(it, pos - 1);
		dato = *it;
		lista.erase(it);
		return true;
	}
	
	int buscar(int dato) {
		list<int>::iterator it = find(lista.begin(), lista.end(), dato);
		if (it == lista.end()) return 0;
		return distance(lista.begin(), it) + 1;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La lista esta vacia\n";
			return;
		}
		cout << "Lista: ";
		for (int x : lista) cout << x << " ";
		cout << endl;
	}
};

int main() {
	ListaLibreria lista;
	int opcion, dato, pos;
	
	cout << "--- Lista Dinamica con Libreria POO ---\n";
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
