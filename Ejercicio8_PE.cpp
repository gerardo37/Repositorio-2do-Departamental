#include <iostream>
#include <stack>
using namespace std;

void push(stack<int> &p, int dato) {
	p.push(dato);
}

bool pop(stack<int> &p, int &dato) {
	if (p.empty()) return false;
	dato = p.top();
	p.pop();
	return true;
}

bool cima(stack<int> &p, int &dato) {
	if (p.empty()) return false;
	dato = p.top();
	return true;
}

// Recibe una copia de la pila para poder vaciarla sin afectar la original
void mostrar(stack<int> copia) {
	if (copia.empty()) {
		cout << "La pila esta vacia\n";
		return;
	}
	cout << "Pila (de la cima a la base): ";
	while (!copia.empty()) {
		cout << copia.top() << " ";
		copia.pop();
	}
	cout << endl;
}

int main() {
	stack<int> pila;
	int opcion, dato;
	
	cout << "--- Pila Dinamica con Libreria PE ---\n";
	do {
		cout << "\n1.Push 2.Pop 3.Cima 4.Mostrar 0.Salir\nOpcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Dato a apilar: ";
			cin >> dato;
			push(pila, dato);
			cout << "Dato apilado\n";
			break;
		case 2:
			if (pop(pila, dato)) cout << "Dato desapilado: " << dato << endl;
			else cout << "Pila vacia: no se puede desapilar\n";
			break;
		case 3:
			if (cima(pila, dato)) cout << "Cima: " << dato << endl;
			else cout << "Pila vacia\n";
			break;
		case 4:
			mostrar(pila);
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
