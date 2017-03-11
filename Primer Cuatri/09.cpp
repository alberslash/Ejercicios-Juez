

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
int resolver(string cadena, string cadenaAbuscar) {
	int i = 0;
	int j = 0;
	int contador = 0;

	while (i < cadena.size()){
		if (cadena[i] == cadenaAbuscar[j]){
			i++;
			j++;
		}
		else i++;

		if (j == cadenaAbuscar.size()){
			contador++;
			j = 0;
		}
	}

	return contador;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	string cadena, cadenaAbuscar;

	getline(cin, cadena);
	
	if (!std::cin)
		return false;

	getline(cin, cadenaAbuscar);

	cout << cadena << "holi" << cadenaAbuscar << endl;
	int contador = resolver(cadena, cadenaAbuscar);
	cout << contador << endl;


	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//

	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
system("PAUSE");
//#endif

	return 0;
}

