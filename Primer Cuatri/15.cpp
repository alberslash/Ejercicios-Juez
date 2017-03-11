

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

typedef int tArray[1000][1000];


// función que resuelve el problema
// comentario sobre el coste, O(f(N))


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int filas = 0, columnas = 0;
	bool cierto = false;
	tArray array;

	cin >> filas;
	cin>> columnas;

	if (!std::cin)
		return false;
	int contador = 0;

	for (int i = 0; i < filas ; i++){
		for (int j = 0; j < columnas; j++){
			cin >> array[i][j];
			if (array[i][j] == i) contador++;
			cierto = true;
		}
	}

	cout << contador << endl;

	// escribir sol


	return cierto;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
		std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
//system("PAUSE");
	#endif

	return 0;
}
