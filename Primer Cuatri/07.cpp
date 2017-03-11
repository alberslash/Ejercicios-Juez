// Grupo E13, Alberto fernandez-baillo
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

void resolver(vector<string> vector, int &primero, int &ultimo){
	string blanco = "FFFFFF";
	int contador = 0;
	bool correcto = true;
	int aux = 0;
	for (int i = 0; i < vector.size(); i++){

		if (vector[i] == blanco){
			contador++;
			correcto = true;
		}
		else correcto = false;
		if (aux < contador){

			if (contador == 1)
				primero = i;
			else primero = i - aux;
			ultimo = i;
			aux = contador;
		}
		if (!correcto) contador = 0;

	}
	if (aux == 0){
		primero = 0;
		ultimo = -1;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int m, n;
	cin >> m;
	cin >> n;
	if (!std::cin)
		return false;
	vector<string> colorines(n);
	int primero = 0, ultimo = 0;
	for (int j = 0; j < m; j++){
		for (size_t i = 0; i < n; i++)
		{
			cin >> colorines[i];
		}
		resolver(colorines, primero, ultimo);
		cout << primero << " " << ultimo << endl;
		ultimo = 0;
	}

	// escribir sol


	return true;

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