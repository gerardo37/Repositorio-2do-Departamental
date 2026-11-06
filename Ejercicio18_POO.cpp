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

class OrdenadorQuick {
private:
	bool mayor(int a, int b)         { return a > b; }
	bool mayor(char a, char b)       { return a > b; }
	bool mayor(Persona a, Persona b) { return a.getEdad() > b.getEdad(); }
	
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
			
public:
				template <typename T>
				void ordenar(T arr[], int n) { quickSort(arr, 0, n - 1); }
};

int main() {
	int n;
	int enteros[MAX];
	char caracteres[MAX];
	Persona personas[MAX];
	OrdenadorQuick ordenador;
	
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
		string nom;
		int e;
		cout << "Nombre de persona " << i + 1 << ": ";
		cin >> nom;
		cout << "Edad de persona " << i + 1 << ": ";
		cin >> e;
		personas[i].setNombre(nom);
		personas[i].setEdad(e);
	}
	
	ordenador.ordenar(enteros, n);
	ordenador.ordenar(caracteres, n);
	ordenador.ordenar(personas, n);
	
	cout << "\nResultados POO\n";
	cout << "Enteros ordenados: ";
	for (int i = 0; i < n; i++) cout << enteros[i] << " ";
	cout << "\nCaracteres ordenados: ";
	for (int i = 0; i < n; i++) cout << caracteres[i] << " ";
	cout << "\nPersonas ordenadas por edad: ";
	for (int i = 0; i < n; i++)
		cout << personas[i].getNombre() << " (" << personas[i].getEdad() << ") ";
	cout << endl;
	return 0;
}
