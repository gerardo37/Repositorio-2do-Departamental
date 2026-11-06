#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Persona {
	string nombre;
	int edad;
};

bool mayor(int a, int b)         { return a > b; }
bool mayor(char a, char b)       { return a > b; }
bool mayor(Persona a, Persona b) { return a.edad > b.edad; }

template <typename T>
	void burbujaIndirecta(T* ptr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (mayor(*ptr[j], *ptr[j + 1])) {
				T* aux = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = aux;
	}
}
	
	int main() {
		int n;
		int enteros[MAX];
		char caracteres[MAX];
		Persona personas[MAX];
		int* ptrEnteros[MAX];
		char* ptrCaracteres[MAX];
		Persona* ptrPersonas[MAX];
		
		cout << "Cantidad de elementos (max 100): ";
		cin >> n;
		
		cout << "\n--- Captura de Enteros ---\n";
		for (int i = 0; i < n; i++) {
			cout << "Ingresa entero " << i + 1 << ": ";
			cin >> enteros[i];
			ptrEnteros[i] = &enteros[i];
		}
		cout << "\n--- Captura de Caracteres ---\n";
		for (int i = 0; i < n; i++) {
			cout << "Ingresa caracter " << i + 1 << ": ";
			cin >> caracteres[i];
			ptrCaracteres[i] = &caracteres[i];
		}
		cout << "\n--- Captura de Personas ---\n";
		for (int i = 0; i < n; i++) {
			cout << "Nombre de persona " << i + 1 << ": ";
			cin >> personas[i].nombre;
			cout << "Edad de persona " << i + 1 << ": ";
			cin >> personas[i].edad;
			ptrPersonas[i] = &personas[i];
		}
		
		burbujaIndirecta(ptrEnteros, n);
		burbujaIndirecta(ptrCaracteres, n);
		burbujaIndirecta(ptrPersonas, n);
		
		cout << "\nResultados PE\n";
		cout << "Enteros originales: ";
		for (int i = 0; i < n; i++) cout << enteros[i] << " ";
		cout << "\nEnteros ordenados (indirecto): ";
		for (int i = 0; i < n; i++) cout << *ptrEnteros[i] << " ";
		
		cout << "\nCaracteres originales: ";
		for (int i = 0; i < n; i++) cout << caracteres[i] << " ";
		cout << "\nCaracteres ordenados (indirecto): ";
		for (int i = 0; i < n; i++) cout << *ptrCaracteres[i] << " ";
		
		cout << "\nPersonas originales: ";
		for (int i = 0; i < n; i++) cout << personas[i].nombre << " (" << personas[i].edad << ") ";
		cout << "\nPersonas ordenadas por edad (indirecto): ";
		for (int i = 0; i < n; i++) cout << ptrPersonas[i]->nombre << " (" << ptrPersonas[i]->edad << ") ";
		cout << endl;
		return 0;
	}
