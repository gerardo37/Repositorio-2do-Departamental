#include <iostream>
#include <string>
using namespace std;

struct Persona {
	string nombre;
	int edad;
};

// Criterio de comparación para cada tipo de dato
bool mayor(int a, int b)         { return a > b; }
bool mayor(char a, char b)       { return a > b; }
bool mayor(Persona a, Persona b) { return a.edad > b.edad; }

// Burbuja genérico: sirve para int, char y Persona
template <typename T>
	void burbuja(T arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (mayor(arr[j], arr[j + 1])) {
				T aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
	}
}
	
	int main() {
		const int N = 2;
		int enteros[N];
		char caracteres[N];
		Persona personas[N];
		
		cout << "--- Captura de Enteros ---\n";
		for (int i = 0; i < N; i++) {
			cout << "Ingresa entero " << i + 1 << ": ";
			cin >> enteros[i];
		}
		cout << "\n--- Captura de Caracteres ---\n";
		for (int i = 0; i < N; i++) {
			cout << "Ingresa caracter " << i + 1 << ": ";
			cin >> caracteres[i];
		}
		cout << "\n--- Captura de Personas ---\n";
		for (int i = 0; i < N; i++) {
			cout << "Nombre de persona " << i + 1 << ": ";
			cin >> personas[i].nombre;
			cout << "Edad de persona " << i + 1 << ": ";
			cin >> personas[i].edad;
		}
		
		burbuja(enteros, N);
		burbuja(caracteres, N);
		burbuja(personas, N);
		
		cout << "\nResultados PE\n";
		cout << "Enteros ordenados: ";
		for (int i = 0; i < N; i++) cout << enteros[i] << " ";
		cout << "\nCaracteres ordenados: ";
		for (int i = 0; i < N; i++) cout << caracteres[i] << " ";
		cout << "\nPersonas ordenadas por edad: ";
		for (int i = 0; i < N; i++) cout << personas[i].nombre << " (" << personas[i].edad << ") ";
		cout << endl;
		return 0;
	}
	
