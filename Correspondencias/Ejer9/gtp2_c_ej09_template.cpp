#include <iostream>
#include <list>
#include <map>
#include <graphviz.hpp>
#include <algorithm>
using namespace aed;
using namespace std;

void is_part_of_hamilt(map<int,list<int>>& G, list<int>::iterator posicion, list<int> &L, list<int> &visitados){
	if(posicion == L.end()) return;
	if (find(visitados.begin(), visitados.end(), *posicion) != visitados.end()) return;
	visitados.push_back(*posicion);
	int nodo = *posicion;
	++posicion;
	auto it = G[nodo].begin();
	while(it != G[nodo].end()){
		if (*it == *posicion){
			is_part_of_hamilt(G, posicion, L, visitados);
			break;
		}
		it++;
	}
}

/// isHamilt. Dado un grafo map<int, list<int> >G y una lista de vertices list<int> L determinar
/// si L es un camino hamiltoniano en G.
bool is_hamilt(map<int,list<int>>& G, list<int>& L) {
	list<int>nodos;
	for(auto const pair : G){
		nodos.push_back(pair.first);
	}
	list<int>visitados;
	auto it = L.begin();
	if(G.find(*it) != G.end()){
		is_part_of_hamilt(G, it, L, visitados);
	}
	if(visitados != L) return false;
	visitados.sort();
	return visitados == nodos;
}
 
int main(int argc, char *argv[]) {
	map<int, list<int>> G = {
		{1, {2,6}},
		{2, {1,3,4,5}},
		{3, {2,5,7}},
		{4, {2,6}},
		{5, {2,3}},
		{6, {1,4,7}},
		{7, {3,6}}
	};
	list<int> LH = {1,6,4,2,5,3,7};
	cout<< "LH es camino hamiltoniano? "<< is_hamilt(G,LH)<<endl;
	graph2dot(G);
	return 0;
}
