// Grupo E13, Alberto FErnandez-BAillo
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
void resolver(vector<int>&principal, const vector<int>aux){

	int i = 0, j = 0;
	while (i <= principal.size() - 1 && j <= aux.size() - 1){
		if (aux[j] < principal[i]){
			j++;
		}
		else if (aux[j] == principal[i]){
			j++;
			i++;
		}
		else if (aux[j] > principal[i]){
			principal[i] = 0;
			i++;
		}
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada


	int numVectores = 0, i, j, valor;
	vector<int>principal;
	vector<int>aux;

	cin >> numVectores;

	cin >> valor;
	while (valor != 0){
		principal.push_back(valor);
		cin >> valor;

	}
	for (int w = 1; w < numVectores; w++){
	
		
			int num = 0;
			cin >> num;
			while (num != 0){
				aux.push_back(num);
				cin >> num;

			}
			resolver(principal, aux);
			aux.clear();
	}
	bool escrito = false;
	if (principal[0] != 0){
		cout << principal[0];
		escrito = true;
	}
	for (int k= 1; k < principal.size(); k++){
		if (escrito) cout << " ";

		if (principal[k] != 0){
			cout << principal[k];
			escrito = true;
		}
		else escrito = false;
	}
	cout << endl;
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