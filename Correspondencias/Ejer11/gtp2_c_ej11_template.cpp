#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
// #include <graphviz.hpp>
// using namespace aed;
using namespace std;

typedef map<char, list<char>> graph;

void coloreado(graph &G, graph &colors, set<int> &no_col, set<int> &nuevo_color,
			   vector<int> &tabla_color, int color){
				
}

void coloreado(graph &G, graph &colors){
	auto it = G.begin();
	vector<int>tabla_color = {1,2,3,4,5,6,7,8,9,};
	colors['red'].push_back(it -> first);

	
}

int main()
{
	graph G = {{'a', {'e'}},
			   {'b', {'c', 'd'}},
			   {'c', {'b', 'e'}},
			   {'d', {'b', 'e'}},
			   {'e', {'a', 'c'}}};

	// graph2dot(G);

	return 0;
}
