#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

void genera_componente_conexa(map<int, list<int>>&G, list<int>& visitados,
							  int nodo, list<int>& componente_actual){
	visitados.push_back(nodo);
	componente_actual.push_back(nodo);
	
	for (auto vecino : G[nodo]) {
		if (find(visitados.begin(), visitados.end(), vecino) == visitados.end()) 
			genera_componente_conexa(G, visitados, vecino, componente_actual);
	}
}

list<list<int>> compConexas(map<int,list<int>>& G){
	list<list<int>> CC;
	list<int>visitados;
	auto it = G.begin();
	while(visitados.size() < G.size()){ 
		if(it == G.end()) it == G.begin();
		
		if(find(visitados.begin(), visitados.end(), it -> first) == visitados.end()){
			list<int> componente_actual;
			genera_componente_conexa(G,visitados, it -> first, componente_actual);
			CC.push_back(componente_actual);
		}
		
		it++;
	}
	
	return CC;
}
	
	int main() {		
		map<int,list<int>> G={
			{0,{1}},
		{1,{0,3,4}},
			{2,{3}},
		{3,{1,2}},
			{4,{1}},
		{5,{6}},
			{6,{5,7}},
		{7,{6}}
		};
		graph2dot(G);
		list<list<int>> CC = compConexas(G);
		
		cout<<"Componentes conexas: "<<endl;
		for(auto cc : CC){
			cout<<"( ";
			for(auto x : cc){
				cout<<x<<" ";
			}
			cout<<")"<<endl;
		}
		
		return 0;
	}
	
