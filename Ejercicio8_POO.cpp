#include <iostream>
#include <stack>
using namespace std;

class PilaLibreria {
private:
	stack<int> pila;
public:
	bool vacia() { return pila.empty(); }
	
	void push(int dato) {
		pila.push(dato);
	}
	
	bool pop(int &dato) {
		if (vacia()) return false;
		dato = pila.top();
		pila.pop();
		return true;
	}
	
	bool cima(int &dato) {
		if (vacia()) return false;
		dato = pila.top();
		return true;
	}
	
	void mostrar() {
		if (vacia()) {
			cout << "La pila esta vacia\n";
			return;
		}
		stack<int> copia = pila;
		cout << "Pila (de la cima a la base): ";
		while (!copia.empty()) {
			cout << copia.top() << " ";
			copia.pop();
		}
		cout << endl;
	}
};

int main() {
	PilaLibreria pila;
	int opcion, dato;
	
	cout << "--- Pila Dinamica con Libreria POO ---\n";
	do {
		cout << "\n1.Push 2.Pop 3.Cima 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a apilar: ";
			cin >> dato;
			pila.push(dato);
			cout << "Dato apilado\n";
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
