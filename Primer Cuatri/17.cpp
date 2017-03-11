// Grupo XYZ, Alberto Fernandez-BAillo
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
int resolver(const vector<char> v, int tam, int numr, int numz){
	int contador = 0, contadorR, contadorZ; 
	for (int j = 0; j <= (v.size() - tam); j++){
		contadorR = 0, contadorZ = 0;

		for (int l = j; l < (tam + j); l++){
			if (v[l] == 'r') contadorR++;
			else if (v[l] == 'z') contadorZ++;
		}
		if (contadorR >= numr && contadorZ >= numz) contador++;


	}
	return contador;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int tamanio, tam, numr, numz, contador;
	cin >> tamanio >> tam >> numr >> numz;

	vector<char> v(tamanio);
	for (int i = 0; i < v.size(); i++){
		cin >> v[i];
	}
	contador = resolver(v, tam, numr, numz);
	cout << contador << endl;
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