#include <iostream>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef map<int, list<int>> graph;

void printList(const list<list<int>>& listaDeListas) {
	for (const auto& sublista : listaDeListas) {
		for (const auto& elem : sublista) {
			cout << elem << " ";
		}
		cout << endl;
	}
}

void dist(graph& G, int x, list<list<int>>& LL, set<int>& visitados) {
	list<int> capa_actual = { x }; 
	visitados.insert(x);
	
	while (!capa_actual.empty()) {
		list<int> capa_siguiente;
		
		for (int nodo : capa_actual) {
			for (int vecino : G[nodo]) {
				if (visitados.find(vecino) == visitados.end()) {
					capa_siguiente.push_back(vecino);
					visitados.insert(vecino);
				}
			}
		}
		
		if (!capa_siguiente.empty()) {
			LL.push_back(capa_siguiente);
		}
		capa_actual = capa_siguiente;
	}
}

list<list<int>> distancia(graph& G, int x) {
	list<list<int>> LL;
	set<int> visitados;
	
	if (G.find(x) == G.end()) return LL;
	
	LL.push_back({ x });
	dist(G, x, LL, visitados);
	return LL;
}

int main() {
	graph G = {
		{0, {1}},
	{1, {0, 3, 4, 5}},
		{2, {3}},
	{3, {1, 2}},
		{4, {1}},
	{5, {6, 1}},
		{6, {5, 7}},
	{7, {6}}
	};
	list<list<int>> D = distancia(G, 1);
	printList(D);
	return 0;
}







