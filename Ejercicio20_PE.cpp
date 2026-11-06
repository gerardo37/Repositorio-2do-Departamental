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
	void mezclar(T* ptr[], int ini, int med, int fin) {
	T* aux[MAX];
	int i = ini, j = med + 1, k = 0;
	while (i <= med && j <= fin) {
		if (mayor(*ptr[i], *ptr[j])) aux[k++] = ptr[j++];
		else                         aux[k++] = ptr[i++];
	}
	while (i <= med) aux[k++] = ptr[i++];
	while (j <= fin) aux[k++] = ptr[j++];
	for (k = 0; k <= fin - ini; k++) ptr[ini + k] = aux[k];
}
	
	template <typename T>
		void mergeSortIndirecto(T* ptr[], int ini, int fin) {
		if (ini >= fin) return;
		int med = (ini + fin) / 2;
		mergeSortIndirecto(ptr, ini, med);
		mergeSortIndirecto(ptr, med + 1, fin);
		mezclar(ptr, ini, med, fin);
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
			
			mergeSortIndirecto(ptrEnteros, 0, n - 1);
			mergeSortIndirecto(ptrCaracteres, 0, n - 1);
			mergeSortIndirecto(ptrPersonas, 0, n - 1);
			
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
