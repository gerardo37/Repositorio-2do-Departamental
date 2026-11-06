#include <iostream>
using namespace std;

const int MAX = 5;

class ListaEstatica {
private:
	int datos[MAX];
	int cantidad;
public:
	ListaEstatica() { cantidad = 0; }
	
	int getCantidad() { return cantidad; }
	bool vacia()      { return cantidad == 0; }
	bool llena()      { return cantidad == MAX; }
	
	bool insertar(int pos, int dato) {
		if (llena() || pos < 1 || pos > cantidad + 1) return false;
		for (int i = cantidad; i >= pos; i--) datos[i] = datos[i - 1];
		datos[pos - 1] = dato;
		cantidad++;
		return true;
	}
	
	bool eliminar(int pos, int &dato) {
		if (pos < 1 || pos > cantidad) return false;
		dato = datos[pos - 1];
		for (int i = pos - 1; i < cantidad - 1; i++) datos[i] = datos[i + 1];
		cantidad--;
		return true;
	}
	
	int buscar(int dato) {
		for (int i = 0; i < cantidad; i++)
			if (datos[i] == dato) return i + 1;
		return 0;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La lista esta vacia\n";
			return;
		}
		cout << "Lista: ";
		for (int i = 0; i < cantidad; i++) cout << datos[i] << " ";
		cout << endl;
	}
};

int main() {
	ListaEstatica lista;
	int opcion, dato, pos;
	
	cout << "--- Lista Estatica POO (capacidad " << MAX << ") ---\n";
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
			else cout << "Lista llena o posicion invalida\n";
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
