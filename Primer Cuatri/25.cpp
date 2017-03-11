// Grupo E13, Alberto Fernandez - Baillo
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


long long resolver(long long penultimo, long long ultimo, long long numero) {
	if (numero > 1) {
		return resolver(ultimo, ultimo + penultimo, numero - 1);
	}
	else if (numero == 1){
		return ultimo;
	}
	else{
		return penultimo;
	}

}
bool resuelveCaso() {
	// leer los datos de la entrada
	long long numero = 0;
	cin >> numero;
	if (!std::cin)
		return false;
	long long sol = resolver(0, 1, numero);
	cout << sol << endl;
	// escribir sol
}



int main() {
	// Para la entrada por fichero.
//	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

//
	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);

	//system("PAUSE");
#endif

	return 0;
}