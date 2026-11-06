#include <iostream>
#include <string>
using namespace std;

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

class OrdenadorBurbuja {
private:
	// Criterio de comparación para cada tipo de dato
	bool mayor(int a, int b)         { return a > b; }
	bool mayor(char a, char b)       { return a > b; }
	bool mayor(Persona a, Persona b) { return a.getEdad() > b.getEdad(); }
public:
		template <typename T>
		void ordenar(T arr[], int n) {
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < n - 1 - i; j++)
					if (mayor(arr[j], arr[j + 1])) {
						T aux = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = aux;
			}
		}
};

int main() {
	const int N = 2;
	int enteros[N];
	char caracteres[N];
	Persona personas[N];
	OrdenadorBurbuja ordenador;
	
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
		string n;
		int e;
		cout << "Nombre de persona " << i + 1 << ": ";
		cin >> n;
		cout << "Edad de persona " << i + 1 << ": ";
		cin >> e;
		personas[i].setNombre(n);
		personas[i].setEdad(e);
	}
	
	ordenador.ordenar(enteros, N);
	ordenador.ordenar(caracteres, N);
	ordenador.ordenar(personas, N);
	
	cout << "\nResultados POO\n";
	cout << "Enteros ordenados: ";
	for (int i = 0; i < N; i++) cout << enteros[i] << " ";
	cout << "\nCaracteres ordenados: ";
	for (int i = 0; i < N; i++) cout << caracteres[i] << " ";
	cout << "\nPersonas ordenadas por edad: ";
	for (int i = 0; i < N; i++)
		cout << personas[i].getNombre() << " (" << personas[i].getEdad() << ") ";
	cout << endl;
	return 0;
}
