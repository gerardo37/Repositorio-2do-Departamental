#include <iostream>
using namespace std;

const int MAX = 5;

class ColaEstatica {
private:
	int datos[MAX];
	int frente;
	int cantidad;
public:
	ColaEstatica() {
		frente = 0;
		cantidad = 0;
	}
	
	bool vacia() { return cantidad == 0; }
	bool llena() { return cantidad == MAX; }
	
	bool encolar(int dato) {
		if (llena()) return false;
		datos[(frente + cantidad) % MAX] = dato;
		cantidad++;
		return true;
	}
	
	bool desencolar(int &dato) {
		if (vacia()) return false;
		dato = datos[frente];
		frente = (frente + 1) % MAX;
		cantidad--;
		return true;
	}
	
	bool primero(int &dato) {
		if (vacia()) return false;
		dato = datos[frente];
		return true;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La cola esta vacia\n";
			return;
		}
		cout << "Cola (del frente al final): ";
		for (int i = 0; i < cantidad; i++)
			cout << datos[(frente + i) % MAX] << " ";
		cout << endl;
	}
};

int main() {
	ColaEstatica cola;
	int opcion, dato;
	
	cout << "--- Cola Estatica POO (capacidad " << MAX << ") ---\n";
	do {
		cout << "\n1.Encolar 2.Desencolar 3.Primero 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a encolar: ";
			cin >> dato;
			if (cola.encolar(dato)) cout << "Dato encolado\n";
			else cout << "Cola llena: no se puede encolar\n";
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
