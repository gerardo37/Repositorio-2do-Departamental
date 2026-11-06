#include <iostream>
#include <queue>
using namespace std;

void encolar(queue<int> &c, int dato) {
	c.push(dato);
}

bool desencolar(queue<int> &c, int &dato) {
	if (c.empty()) return false;
	dato = c.front();
	c.pop();
	return true;
}

bool primero(queue<int> &c, int &dato) {
	if (c.empty()) return false;
	dato = c.front();
	return true;
}

// Recibe una copia de la cola para poder vaciarla sin afectar la original
void mostrar(queue<int> copia) {
	if (copia.empty()) {
		cout << "La cola esta vacia\n";
		return;
	}
	cout << "Cola (del frente al final): ";
	while (!copia.empty()) {
		cout << copia.front() << " ";
		copia.pop();
	}
	cout << endl;
}

int main() {
	queue<int> cola;
	int opcion, dato;
	
	cout << "--- Cola Dinamica con Libreria PE ---\n";
	do {
		cout << "\n1.Encolar 2.Desencolar 3.Primero 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a encolar: ";
			cin >> dato;
			encolar(cola, dato);
			cout << "Dato encolado\n";
			break;
		case 2:
			if (desencolar(cola, dato)) cout << "Dato desencolado: " << dato << endl;
			else cout << "Cola vacia: no se puede desencolar\n";
			break;
		case 3:
			if (primero(cola, dato)) cout << "Primero: " << dato << endl;
			else cout << "Cola vacia\n";
			break;
		case 4:
			mostrar(cola);
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
