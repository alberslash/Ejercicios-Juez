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
#include <string>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(vector<int> vector, int n) {
	int ceros = 0, unos = 0;
	int pos = -1;
	int i = 0;
	for  (i = 0; i < n; i++){
		
		if (vector[i] == 0)	ceros++;
		else if (vector[i] == 1) unos++;
		if (ceros == unos) pos = i;
	}
	return pos;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n = 0, i = 0, pos = 0;
	bool salir = false;
	cin >> n;
	vector<int> vector(n);
	for (int i = 0; i < n; i++){
		cin >> vector[i];
	}
	pos = resolver(vector, n);
	cout << pos << endl;
	
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