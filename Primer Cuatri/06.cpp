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
#include <string>

using namespace std;


// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(string palabra) {
	int mayor = 0;
	int ordenados = 1;
	
	int longitud = palabra.size() - 1;
	if (longitud == 0) mayor = 1;
	else{
		for (int i = 0; i < longitud; i++)	{
			if (palabra[i] < palabra[i + 1]) ordenados++;
			else ordenados = 1;
			if (mayor < ordenados) mayor = ordenados;
			
		}
	}
	return mayor;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string palabra;
	int  ordenados = 1;
	cin >> palabra;
	if (palabra == "XXX")
		return false;
	
	ordenados = resolver(palabra);
	cout << palabra.size() << " " << ordenados << endl;
	// escribir sol

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/04");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//

	while (resuelveCaso())
		;

//
//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
	/*system("PAUSE");*/
//#endif

	return 0;
}