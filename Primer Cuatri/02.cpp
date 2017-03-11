// Grupo E13, Alberto Fernandez-Baillo
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

// Con la postcondicion se deduce que el programa tiene que comprobar que todos los numeros entre 0 y p tienen que ser mas pequeños que todos
// los numeros comprendidos entre p y n recorriendo el vector 1 sola vez.
// Para ello se hace un recorrido entre 0 y p buscando cual es el numero mas grande, se hace otro recorrido entre p y n para saber cual es
// el numero mas pequeño, se compara y estara bien siempre y cuando el numero mas grande comprendido entre 0 y p sea menor que el numero 
// mas pequeño comprendido entre p y n.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX = 50;
typedef int tArray[MAX];

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
bool resolver(const std::vector<int> & vector,int p , int tamanio) {

	bool encontrado = true;
	int fin = vector.size();
	int i = 0;
	int min = vector[i];
	int max = vector[p];
	int aux = 0;
	if ( )
	while (i < tamanio){
		if (i <= p && p != tamanio - 1)
		{
			aux = vector[i];
			if (vector[i] < min) min = aux;
		}
		else if (i < tamanio) {
			aux = vector[i];
			if (max < vector[i]) max = aux;
		}
		
		i++;
	}
	if (min < max)	encontrado = false;
	return encontrado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, p;
	bool encontrado = false;
	std::cin >> n;
	std::cin >> p;
	std::vector<int> v(n);

	for (size_t i = 0; i < v.size(); i++) {
		std::cin >> v[i];
	}

	encontrado = resolver(v, p, n);
	if (encontrado)
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


//	 /*Para restablecer entrada. Comentar para acepta el reto*/
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
	system("PAUSE");
//#endif

	return 0;
}