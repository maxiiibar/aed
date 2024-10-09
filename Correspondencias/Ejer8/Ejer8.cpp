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
	list<int>aux;
	bool condicion = false;
	for (const auto& pair : G){
		auto it = aux.begin();
		while(it != aux.end()){
			if(*it==pair.first) condicion = true;
			it++;
		}
		if(!condicion)aux.push_back(pair.first);
		else {
			D.push_back(aux);
			aux.erase(aux.begin(), aux.end());
			aux.push_back(pair.first);
			condicion = false;
		}
		it = aux.begin();
		auto it2 = pair.second.begin();
		auto end = pair.second.end();
		while(it2 != end){
			while(it != aux.end()){
				
			}
			it2++;
		}
	}
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
	
	return 0;
}
