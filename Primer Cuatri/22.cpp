// Grupo E13 Alberto Fernandez- Baillo
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
void buscar(vector<int> prisioneros, int i, int &x) {

	if (i == prisioneros.size() + 1) x = -1;
	else if ((prisioneros[i] + 1) != prisioneros[i + 1]) x = i;
	else  buscar(prisioneros, i + 1, x);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	vector<int>prisioneros;
	int falta = 0, ini = 0, fin = 0, i = ini, aux = 0;
	bool salir = false;
	cin >> ini;
	cin >> fin;
	while (!salir){
		cin >> aux;
		prisioneros.push_back(aux);
		if (prisioneros[i] == fin) salir = true;
		else i++;
	}
	i = 0;
	int  x = 0;
	buscar(prisioneros, i, x);
	cout << prisioneros[x] + 1 << endl;
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
	// system("PAUSE");
#endif

	return 0;
}