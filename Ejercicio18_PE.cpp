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
	int particion(T arr[], int ini, int fin) {
	T pivote = arr[fin];
	int i = ini - 1;
	for (int j = ini; j < fin; j++) {
		if (mayor(pivote, arr[j])) {
			i++;
			T aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	T aux = arr[i + 1];
	arr[i + 1] = arr[fin];
	arr[fin] = aux;
	return i + 1;
}
	
	template <typename T>
		void quickSort(T arr[], int ini, int fin) {
		if (ini >= fin) return;
		int p = particion(arr, ini, fin);
		quickSort(arr, ini, p - 1);
		quickSort(arr, p + 1, fin);
	}
		
		int main() {
			int n;
			int enteros[MAX];
			char caracteres[MAX];
			Persona personas[MAX];
			
			cout << "Cantidad de elementos (max 100): ";
			cin >> n;
			
			cout << "\n--- Captura de Enteros ---\n";
			for (int i = 0; i < n; i++) {
				cout << "Ingresa entero " << i + 1 << ": ";
				cin >> enteros[i];
			}
			cout << "\n--- Captura de Caracteres ---\n";
			for (int i = 0; i < n; i++) {
				cout << "Ingresa caracter " << i + 1 << ": ";
				cin >> caracteres[i];
			}
			cout << "\n--- Captura de Personas ---\n";
			for (int i = 0; i < n; i++) {
				cout << "Nombre de persona " << i + 1 << ": ";
				cin >> personas[i].nombre;
				cout << "Edad de persona " << i + 1 << ": ";
				cin >> personas[i].edad;
			}
			
			quickSort(enteros, 0, n - 1);
			quickSort(caracteres, 0, n - 1);
			quickSort(personas, 0, n - 1);
			
			cout << "\nResultados PE\n";
			cout << "Enteros ordenados: ";
			for (int i = 0; i < n; i++) cout << enteros[i] << " ";
			cout << "\nCaracteres ordenados: ";
			for (int i = 0; i < n; i++) cout << caracteres[i] << " ";
			cout << "\nPersonas ordenadas por edad: ";
			for (int i = 0; i < n; i++) cout << personas[i].nombre << " (" << personas[i].edad << ") ";
			cout << endl;
			return 0;
		}
