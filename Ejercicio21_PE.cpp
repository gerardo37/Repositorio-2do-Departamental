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
	int particion(T* ptr[], int ini, int fin) {
	T* pivote = ptr[fin];
	int i = ini - 1;
	for (int j = ini; j < fin; j++) {
		if (mayor(*pivote, *ptr[j])) {
			i++;
			T* aux = ptr[i];
			ptr[i] = ptr[j];
			ptr[j] = aux;
		}
	}
	T* aux = ptr[i + 1];
	ptr[i + 1] = ptr[fin];
	ptr[fin] = aux;
	return i + 1;
}
	
	template <typename T>
		void quickSortIndirecto(T* ptr[], int ini, int fin) {
		if (ini >= fin) return;
		int p = particion(ptr, ini, fin);
		quickSortIndirecto(ptr, ini, p - 1);
		quickSortIndirecto(ptr, p + 1, fin);
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
			
			quickSortIndirecto(ptrEnteros, 0, n - 1);
			quickSortIndirecto(ptrCaracteres, 0, n - 1);
			quickSortIndirecto(ptrPersonas, 0, n - 1);
			
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
