// Grupo E13, Alberto Fernandez-Baillo
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

// Se guarda en un array la cadena de numeros, simultaneamente se va comprobando que numero es el mas grande y cuantas veces se repite

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(std::vector<int> vector, int &contador, int &mayor) {

	mayor = vector[0];

	for (size_t i = 0; i < vector.size(); i++)
	{
		if (vector[i] > mayor)
		{
			mayor = vector[i];
			contador = 1;
		}
		else if (vector[i] == mayor) contador++;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n = 0, contador = 0, mayor = 0;

	std::cin >> n;
	std::vector<int> v(n);
	for (size_t i = 0; i < v.size(); i++) {
		std::cin >> v[i];
	}
	resolver(v, contador, mayor);
	std::cout << mayor << " " << contador << std::endl;
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


	 /*Para restablecer entrada. Comentar para acepta el reto*/
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}