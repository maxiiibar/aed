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
	
void apply_map(list<int> &L, map<int,int> &M, list<int> &ML){
	auto it = L.begin();
	while(it != L.end()){
		for(const auto& pair : M){
			if (*it == pair.first) ML.push_back(pair.second);
		}
		it++;
	}
}

int main() {
	list<int>L = {1,2,3,4,5,6,7,1,2,3};
	map<int, int> M = {{1,2},{2,3},{3,4},{4,5},{7,8}};
	list<int>ML;
	
	apply_map(L,M,ML);
	
	show_list(ML);
	
	return 0;
}
