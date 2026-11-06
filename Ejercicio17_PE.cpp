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
	void mezclar(T arr[], int ini, int med, int fin) {
	T aux[MAX];
	int i = ini, j = med + 1, k = 0;
	while (i <= med && j <= fin) {
		if (mayor(arr[i], arr[j])) aux[k++] = arr[j++];
		else                       aux[k++] = arr[i++];
	}
	while (i <= med) aux[k++] = arr[i++];
	while (j <= fin) aux[k++] = arr[j++];
	for (k = 0; k <= fin - ini; k++) arr[ini + k] = aux[k];
}
	
	template <typename T>
		void mergeSort(T arr[], int ini, int fin) {
		if (ini >= fin) return;
		int med = (ini + fin) / 2;
		mergeSort(arr, ini, med);
		mergeSort(arr, med + 1, fin);
		mezclar(arr, ini, med, fin);
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
			
			mergeSort(enteros, 0, n - 1);
			mergeSort(caracteres, 0, n - 1);
			mergeSort(personas, 0, n - 1);
			
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
