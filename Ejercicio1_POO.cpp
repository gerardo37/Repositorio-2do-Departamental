#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Persona {
private:
	string nombre, ap, am;
	char genero;
	int edad;
	Persona* siguiente;
public:
	Persona() { siguiente = nullptr; }
	void setDatos(string n, string a, string m, char g, int e) {
		nombre = n;
		ap = a;
		am = m;
		genero = g;
		edad = e;
	}
	void setSiguiente(Persona* s) { siguiente = s; }
	Persona* getSiguiente()       { return siguiente; }
	void mostrar() {
		cout << nombre << " " << ap << " " << am
			<< " | Genero: " << genero << " | Edad: " << edad << endl;
	}
};

class Auto {
private:
	float precio;
	int anio;
	Auto* siguiente;
public:
	Auto() { siguiente = nullptr; }
	void setDatos(float p, int a) {
		precio = p;
		anio = a;
	}
	void setSiguiente(Auto* s) { siguiente = s; }
	Auto* getSiguiente()       { return siguiente; }
	void mostrar() {
		cout << "Precio: $" << precio << " | Anio: " << anio << endl;
	}
};

int main() {
	int n;
	Persona personas[MAX];
	Auto autos[MAX];
	
	cout << "Cantidad de personas y autos (max 100): ";
	cin >> n;
	
	cout << "\n--- Captura de Personas ---\n";
	for (int i = 0; i < n; i++) {
		string nom, ap, am;
		char gen;
		int edad;
		cout << "Nombre de persona " << i + 1 << ": ";
		cin >> nom;
		cout << "Apellido paterno: ";
		cin >> ap;
		cout << "Apellido materno: ";
		cin >> am;
		cout << "Genero (M/F): ";
		cin >> gen;
		cout << "Edad: ";
		cin >> edad;
		personas[i].setDatos(nom, ap, am, gen, edad);
		if (i > 0) personas[i - 1].setSiguiente(&personas[i]);
	}
	
	cout << "\n--- Captura de Autos ---\n";
	for (int i = 0; i < n; i++) {
		float precio;
		int anio;
		cout << "Precio del auto " << i + 1 << ": ";
		cin >> precio;
		cout << "Anio del auto " << i + 1 << ": ";
		cin >> anio;
		autos[i].setDatos(precio, anio);
		if (i > 0) autos[i - 1].setSiguiente(&autos[i]);
	}
	
	cout << "\nResultados POO\n";
	cout << "--- Personas (recorridas con punteros) ---\n";
	Persona* p = n > 0 ? personas : nullptr;
	while (p != nullptr) {
		p->mostrar();
		p = p->getSiguiente();
	}
	
	cout << "--- Autos (recorridos con punteros) ---\n";
	Auto* a = n > 0 ? autos : nullptr;
	while (a != nullptr) {
		a->mostrar();
		a = a->getSiguiente();
	}
	return 0;
}
