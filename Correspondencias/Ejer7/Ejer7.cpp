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
	
bool es_camino(map<int,list<int>> G, list<int> &L){
	bool condicion = false;
	auto it = L.begin();
	int aux, cont = 0;
	for(const auto& pair : G){
		aux = *it;
		if(pair.first == aux){
			if(pair.second.empty()) return true;
			cont=0;
			it++;
			aux=*it;
			auto it2 = pair.second.begin();
			while(it2 != pair.second.end()){
				if(aux == *it2){
					condicion = true;
				}
				it2++;
			}
			if(!condicion) return false;
			condicion = false;
		} else cont++;
		if(cont==2) return false;
	}
	return true;
}

int main() {
	map<int, list<int>> G;
	G[1] = {2, 3};
	G[2] = {4};
	G[3] = {4, 5};
	G[4] = {5};
	G[5] = {};
	
	// Caminos de prueba
	list<int> L1 = {1, 2, 4, 5}; // Camino v�lido
	list<int> L2 = {1, 3, 2};    // Camino no v�lido
	list<int> L3 = {1, 3, 5};    // Camino v�lido
	list<int> L4 = {2, 4, 1};    // Camino no v�lido
	list<int> L5 = {1, 3, 4, 5};  // Camino v�lido
	list<int> L6 = {1, 5};        // Camino no v�lido
	
	// Probar los caminos
	cout << "L1 es camino: " << es_camino(G, L1) << endl; // Deber�a imprimir 1
	cout << "L2 es camino: " << es_camino(G, L2) << endl; // Deber�a imprimir 0
	cout << "L3 es camino: " << es_camino(G, L3) << endl; // Deber�a imprimir 1
	cout << "L4 es camino: " << es_camino(G, L4) << endl; // Deber�a imprimir 0
	cout << "L5 es camino: " << es_camino(G, L5) << endl; // Deber�a imprimir 1
	cout << "L6 es camino: " << es_camino(G, L6) << endl; // Deber�a imprimir 0
	
	return 0;
}
