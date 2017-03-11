
// Grupo E13, Alberto Fernandez-Baillo
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(vector<int> vector, int n, int g, int &inicio, int &total) {

	int contador = 0, suma = 0;
	for (int i = 0; i < n; i++){
		if (contador < g){
			suma += vector[i];
			contador++;
			total = suma;
		}
		else {

			suma -= vector[i - g];
			suma += vector[i];
			if (suma >= total){
				total = suma;
				inicio = i - g + 1;
			}

		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int n, g, inicio = 0, total = 0;

	cin >> n >> g;
	vector<int> vector(n);

	for (int i = 0; i < n; i++)
		cin >> vector[i];


	resolver(vector, n, g, inicio, total);
	cout << inicio << " " << total << endl;
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif


	return 0;
}
