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

typedef int tArray[100000];



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(tArray const numeros, int buscar, int ini, int fin, int pos, bool &esta) {
	int medio = (ini + fin) / 2;
	if (fin - ini == 1) {
		if (numeros[fin] > buscar && numeros[ini] < buscar) {
			pos = fin + buscar;
			if (pos != numeros[fin]) esta = false;
		}
		else {

			/*	cout << numeros[medio] << " " << buscar << endl;*/

			if (numeros[medio] < buscar) {
				resolver(numeros, buscar, 0, medio, pos);
			}
			else if (numeros[medio] > buscar) {
				resolver(numeros, buscar, medio, fin, pos);
			}
			else if (numeros[medio] == buscar) {
				pos = numeros[medio] + medio;
				if (pos != numeros[medio + 1]) esta = false;
			}
		}
		return pos;
	}

	// Resuelve un caso de prueba, leyendo de la entrada la
	// configuración, y escribiendo la respuesta
	void resuelveCaso() {
		// leer los datos de la entrada
		tArray numeros;
		int total = 0, buscar = 0, sol = 0, ini = 0, fin = 0, i = 0;
		cin >> total >> buscar;

		for (i = 0; i < total; i++) {
			cin >> numeros[i];
		}
		bool esta;
		resolver(numeros, buscar, 0, total - 1, sol, esta);
		if (!esta) cout << "NO" << endl;
		else cout << sol << endl;

		// escribir sol


	}

	int main() {
		// Para la entrada por fichero.
		// Comentar para acepta el reto
//#ifndef DOMJUDGE
//		std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
//		auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//

		int numCasos;
		std::cin >> numCasos;
		for (int i = 0; i < numCasos; ++i)
			resuelveCaso();


//		//	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//		std::cin.rdbuf(cinbuf);
system("PAUSE");
//#endif

		return 0;
	}