#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Persona {
private:
	string nombre;
	int edad;
public:
	void setNombre(string n) { nombre = n; }
	void setEdad(int e)      { edad = e; }
	string getNombre()       { return nombre; }
	int getEdad()            { return edad; }
};

class OrdenadorMergeIndirecto {
private:
	bool mayor(int a, int b)         { return a > b; }
	bool mayor(char a, char b)       { return a > b; }
	bool mayor(Persona a, Persona b) { return a.getEdad() > b.getEdad(); }
	
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
			void mergeSort(T* ptr[], int ini, int fin) {
			if (ini >= fin) return;
			int med = (ini + fin) / 2;
			mergeSort(ptr, ini, med);
			mergeSort(ptr, med + 1, fin);
			mezclar(ptr, ini, med, fin);
		}
			
public:
				template <typename T>
				void ordenar(T* ptr[], int n) { mergeSort(ptr, 0, n - 1); }
};

int main() {
	int n;
	int enteros[MAX];
	char caracteres[MAX];
	Persona personas[MAX];
	int* ptrEnteros[MAX];
	char* ptrCaracteres[MAX];
	Persona* ptrPersonas[MAX];
	OrdenadorMergeIndirecto ordenador;
	
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
		string nom;
		int e;
		cout << "Nombre de persona " << i + 1 << ": ";
		cin >> nom;
		cout << "Edad de persona " << i + 1 << ": ";
		cin >> e;
		personas[i].setNombre(nom);
		personas[i].setEdad(e);
		ptrPersonas[i] = &personas[i];
	}
	
	ordenador.ordenar(ptrEnteros, n);
	ordenador.ordenar(ptrCaracteres, n);
	ordenador.ordenar(ptrPersonas, n);
	
	cout << "\nResultados POO\n";
	cout << "Enteros originales: ";
	for (int i = 0; i < n; i++) cout << enteros[i] << " ";
	cout << "\nEnteros ordenados (indirecto): ";
	for (int i = 0; i < n; i++) cout << *ptrEnteros[i] << " ";
	
	cout << "\nCaracteres originales: ";
	for (int i = 0; i < n; i++) cout << caracteres[i] << " ";
	cout << "\nCaracteres ordenados (indirecto): ";
	for (int i = 0; i < n; i++) cout << *ptrCaracteres[i] << " ";
	
	cout << "\nPersonas originales: ";
	for (int i = 0; i < n; i++)
		cout << personas[i].getNombre() << " (" << personas[i].getEdad() << ") ";
	cout << "\nPersonas ordenadas por edad (indirecto): ";
	for (int i = 0; i < n; i++)
		cout << ptrPersonas[i]->getNombre() << " (" << ptrPersonas[i]->getEdad() << ") ";
	cout << endl;
	return 0;
}
