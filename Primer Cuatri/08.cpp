// Grupo XYZ, Alberto Fernandez-Baillo
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
int resolverCaso(int v[], int n) {
	int maxIz = v[0];
	int max = v[0];
	int pivote = 0;

	for (int i = 1; i < n; ++i) {
		if (v[i] >= max) {
			max = v[i];
		}
		if (v[i] <= maxIz) {
			pivote = i;
			maxIz = max;
		}
	}
	return pivote;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resolver() {
	int n;
	int v[10000];

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	if (n == 0) {
		cout << 0 << endl;
		return;
	}
	cout << resolverCaso(v, n) << endl;
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
		resolver();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}