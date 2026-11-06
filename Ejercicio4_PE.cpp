#include <iostream>
using namespace std;

const int MAX = 5;

struct Cola {
	int datos[MAX];
	int frente;
	int cantidad;
};

void iniciar(Cola &c) {
	c.frente = 0;
	c.cantidad = 0;
}

bool vacia(Cola &c) { return c.cantidad == 0; }
bool llena(Cola &c) { return c.cantidad == MAX; }

bool encolar(Cola &c, int dato) {
	if (llena(c)) return false;
	c.datos[(c.frente + c.cantidad) % MAX] = dato;
	c.cantidad++;
	return true;
}

bool desencolar(Cola &c, int &dato) {
	if (vacia(c)) return false;
	dato = c.datos[c.frente];
	c.frente = (c.frente + 1) % MAX;
	c.cantidad--;
	return true;
}

bool primero(Cola &c, int &dato) {
	if (vacia(c)) return false;
	dato = c.datos[c.frente];
	return true;
}

void mostrar(Cola &c) {
	if (vacia(c)) {
		cout << "La cola esta vacia\n";
		return;
	}
	cout << "Cola (del frente al final): ";
	for (int i = 0; i < c.cantidad; i++)
		cout << c.datos[(c.frente + i) % MAX] << " ";
	cout << endl;
}

int main() {
	Cola cola;
	iniciar(cola);
	int opcion, dato;
	
	cout << "--- Cola Estatica PE (capacidad " << MAX << ") ---\n";
	do {
		cout << "\n1.Encolar 2.Desencolar 3.Primero 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a encolar: ";
			cin >> dato;
			if (encolar(cola, dato)) cout << "Dato encolado\n";
			else cout << "Cola llena: no se puede encolar\n";
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
