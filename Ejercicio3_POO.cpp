#include <iostream>
using namespace std;

const int MAX = 5;

class PilaEstatica {
private:
	int datos[MAX];
	int tope;
public:
	PilaEstatica() { tope = -1; }
	
	bool vacia() { return tope == -1; }
	bool llena() { return tope == MAX - 1; }
	
	bool push(int dato) {
		if (llena()) return false;
		datos[++tope] = dato;
		return true;
	}
	
	bool pop(int &dato) {
		if (vacia()) return false;
		dato = datos[tope--];
		return true;
	}
	
	bool cima(int &dato) {
		if (vacia()) return false;
		dato = datos[tope];
		return true;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La pila esta vacia\n";
			return;
		}
		cout << "Pila (de la cima a la base): ";
		for (int i = tope; i >= 0; i--) cout << datos[i] << " ";
		cout << endl;
	}
};

int main() {
	PilaEstatica pila;
	int opcion, dato;
	
	cout << "--- Pila Estatica POO (capacidad " << MAX << ") ---\n";
	do {
		cout << "\n1.Push 2.Pop 3.Cima 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a apilar: ";
			cin >> dato;
			if (pila.push(dato)) cout << "Dato apilado\n";
			else cout << "Pila llena: no se puede apilar\n";
			break;
		case 2:
			if (pila.pop(dato)) cout << "Dato desapilado: " << dato << endl;
			else cout << "Pila vacia: no se puede desapilar\n";
			break;
		case 3:
			if (pila.cima(dato)) cout << "Cima: " << dato << endl;
			else cout << "Pila vacia\n";
			break;
		case 4:
			pila.mostrar();
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
