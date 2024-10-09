#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void show_map(const std::map<int, int> &M) {
	for (const auto& pair : M) {
		cout << "Clave: " << pair.first << ", Valor: " << pair.second <<endl;
	}
}

template<typename K, typename V>
void show_map_of_lists(const std::map<K, std::list<V>>& mymap) {
	for (const auto& pair : mymap) {
		std::cout << "Clave: " << pair.first << " -> Valores: ";
		for (const auto& value : pair.second) {
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}
	
void comp_conexas(map<int,list<int>> &G, list<list<int>> &D){
	
}

int main() {
	map<int, list<int>> G;
	G[1] = {2, 3};
	G[2] = {4};
	G[3] = {4, 5};
	G[4] = {5};
	G[5] = {};
	
	// Caminos de prueba
	list<int> L1 = {1, 2, 4, 5}; // Camino válido
	list<int> L2 = {1, 3, 2};    // Camino no válido
	list<int> L3 = {1, 3, 5};    // Camino válido
	list<int> L4 = {2, 4, 1};    // Camino no válido
	list<int> L5 = {1, 3, 4, 5};  // Camino válido
	list<int> L6 = {1, 5};        // Camino no válido
	
	// Probar los caminos
	cout << "L1 es camino: " << es_camino(G, L1) << endl; // Debería imprimir 1
	cout << "L2 es camino: " << es_camino(G, L2) << endl; // Debería imprimir 0
	cout << "L3 es camino: " << es_camino(G, L3) << endl; // Debería imprimir 1
	cout << "L4 es camino: " << es_camino(G, L4) << endl; // Debería imprimir 0
	cout << "L5 es camino: " << es_camino(G, L5) << endl; // Debería imprimir 1
	cout << "L6 es camino: " << es_camino(G, L6) << endl; // Debería imprimir 0
	
	return 0;
}
