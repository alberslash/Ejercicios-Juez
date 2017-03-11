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

using namespace std;
const int n = 100, m = 100;

typedef int tMatriz[n][m];

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(const tMatriz matriz, int n, int m) {
	bool esigual;
	int contador = 0, mayor = 0, valor = matriz[0][0];
	for (int i = 0; i < m; i++){
		esigual = true;
		int j = 0;
		if (valor != matriz[j][i]) valor = -1;
		if (valor == -1)
			contador = 0;
			while (j < n - 1 && esigual){
				if (matriz[j][i] != matriz[j + 1][i])	{
					esigual = false;
					valor = -1;
				}
				else valor = matriz[j][i];
				j++;
			}
			if (esigual){

				contador++;
				if (contador > mayor)
					mayor = contador;
			}
	}
	return mayor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tMatriz matriz;
	int n = 0, m = 0,  veces = 0;
	cin >> n;
	cin >> m;

	if (!std::cin)
		return false;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> matriz[i][j];
		}
	}
	veces = resolver(matriz, n , m);

	// escribir sol
	cout << veces << endl;

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