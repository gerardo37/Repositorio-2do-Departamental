#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Persona {
	string nombre, ap, am;
	char genero;
	int edad;
	Persona* siguiente;
};

struct Auto {
	float precio;
	int anio;
	Auto* siguiente;
};

void mostrar(Persona* p) {
	cout << p->nombre << " " << p->ap << " " << p->am
		<< " | Genero: " << p->genero << " | Edad: " << p->edad << endl;
}

void mostrar(Auto* a) {
	cout << "Precio: $" << a->precio << " | Anio: " << a->anio << endl;
}

int main() {
	int n;
	Persona personas[MAX];
	Auto autos[MAX];
	
	cout << "Cantidad de personas y autos (max 100): ";
	cin >> n;
	
	cout << "\n--- Captura de Personas ---\n";
	for (int i = 0; i < n; i++) {
		cout << "Nombre de persona " << i + 1 << ": ";
		cin >> personas[i].nombre;
		cout << "Apellido paterno: ";
		cin >> personas[i].ap;
		cout << "Apellido materno: ";
		cin >> personas[i].am;
		cout << "Genero (M/F): ";
		cin >> personas[i].genero;
		cout << "Edad: ";
		cin >> personas[i].edad;
		personas[i].siguiente = nullptr;
		if (i > 0) personas[i - 1].siguiente = &personas[i];
	}
	
	cout << "\n--- Captura de Autos ---\n";
	for (int i = 0; i < n; i++) {
		cout << "Precio del auto " << i + 1 << ": ";
		cin >> autos[i].precio;
		cout << "Anio del auto " << i + 1 << ": ";
		cin >> autos[i].anio;
		autos[i].siguiente = nullptr;
		if (i > 0) autos[i - 1].siguiente = &autos[i];
	}
	
	cout << "\nResultados PE\n";
	cout << "--- Personas (recorridas con punteros) ---\n";
	Persona* p = n > 0 ? personas : nullptr;
	while (p != nullptr) {
		mostrar(p);
		p = p->siguiente;
	}
	
	cout << "--- Autos (recorridos con punteros) ---\n";
	Auto* a = n > 0 ? autos : nullptr;
	while (a != nullptr) {
		mostrar(a);
		a = a->siguiente;
	}
	return 0;
}
