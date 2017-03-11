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
bool resolver(string palabra) {

	bool correcto = true;
	int i = 0, longitud = 0;
	longitud = palabra.length() - 1;
	while (i < longitud && correcto)
	{
		if (palabra[i] == palabra[i + 1]) correcto = false;
		else if (palabra[i] > palabra[i + 1])  correcto = false;
		i++;
	}

	return correcto;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string palabra;
	bool sol = false, continuar = true;
	cin >> palabra;
	if (palabra == "XXX")
		return false;
	
	sol = resolver(palabra);
	if (sol) cout << "SI" << endl;
	else cout << "NO" << endl;
	// escribir sol

	return continuar;

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
	/*system("PAUSE");*/
#endif

	return 0;
}