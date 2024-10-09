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
	
void cutoffmap(map<int, list<int>> &M, int p, int q){
	for (auto& pair : M){
		if(pair.first<p or pair.first>=q) M.erase(pair.first);
		else{
			auto it = (pair.second).begin();
			auto end = (pair.second).end();
			while(it != end){
				if(*it < p or *it >= q) (pair.second).erase(it);
				it++;
			}
			if (pair.second.empty()) M.erase(pair.first);
		}
	}
}

int main() {
	
	map<int, list<int>> M = {{1,{2,3,4}},{5,{6,7,8}},{8,{4,5}},{3,{1,3,7}}};
	
	cutoffmap(M,1,6);
	
	show_map_of_lists(M);
	
	return 0;
}
