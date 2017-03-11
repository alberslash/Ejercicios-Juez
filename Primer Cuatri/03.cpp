// Grupo XYZ, Fulano y Mengano
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

int const MAX = 10000;

typedef int tArray[MAX];

// función que resuelve el problema
// comentario sobre el coste, O(tamanio)
void resolver(int &picos, int &valles, tArray array, int tamanio){
	picos = 0;
	valles = 0;
	for (int i = 1; i < tamanio - 1; i++){
		if (array[i - 1] < array[i] && array[i] > array[i + 1])
			picos++;
		else if (array[i - 1] > array[i] && array[i] < array[i + 1])
			valles++;
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamanio, picos, valles;
	cin >> tamanio;
	tArray array;

	for (int i = 0; i < tamanio; i++){
		cin >> array[i];
	}
	resolver(picos, valles, array, tamanio);
	// escribir sol

	cout << picos << " " << valles << endl;


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}