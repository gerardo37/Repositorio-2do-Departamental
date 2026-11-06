#include <iostream>
#include <queue>
using namespace std;

class ColaLibreria {
private:
	queue<int> cola;
public:
	bool vacia() { return cola.empty(); }
	
	void encolar(int dato) {
		cola.push(dato);
	}
	
	bool desencolar(int &dato) {
		if (vacia()) return false;
		dato = cola.front();
		cola.pop();
		return true;
	}
	
	bool primero(int &dato) {
		if (vacia()) return false;
		dato = cola.front();
		return true;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La cola esta vacia\n";
			return;
		}
		queue<int> copia = cola;
		cout << "Cola (del frente al final): ";
		while (!copia.empty()) {
			cout << copia.front() << " ";
			copia.pop();
		}
		cout << endl;
	}
};

int main() {
	ColaLibreria cola;
	int opcion, dato;
	
	cout << "--- Cola Dinamica con Libreria POO ---\n";
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
