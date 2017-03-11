// Grupo E13, Alberto Fernandez-Baillo
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

//Se crea un vector de entrada donde se van a almacenar todos los numeros introducidos por consola.
//Se crea tambien un vector de salida, se llama a la funcion resolver con ambos vectores por parametros.
//Se hace un for que mientras recorre el vector entrada mientras que almacena en el vector salida el primer elemento y a partir de ahi
//se alamcena la suma de los valores contenidos en la posicion anterior del vector salida y en la posicion i del vector entrada
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
void resolver(std::vector<int> vector, std::vector<int> &salida) {

	int i = 0;
	salida.push_back(i);
	salida[i] = vector[i];
	for (size_t i = 1; i < vector.size(); i++)
	{	
		salida.push_back(i);
		salida[i] = salida[i - 1] + vector[i];
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int i = 0, num =0;
	std::vector<int> vector;
	std::vector<int> salida;
	
	vector.push_back(i);
	cin >> vector[i];
	if (!std::cin)
		return false;
	while (vector[i] != 0)
	{
		i++;
		vector.push_back(i);
		cin >> vector[i];	
	}
	
	resolver(vector, salida);
	std::vector<char>::size_type fin = salida.size() - 1;
	for (size_t i = 0; i < fin; i++)
	{
		cout << salida[i] << " ";
		/*if (salida[i] == fin - 1) cout << salida[i] << endl;*/
	}
	cout << endl;
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
	/*system("PAUSE");*/
#endif

	return 0;
}