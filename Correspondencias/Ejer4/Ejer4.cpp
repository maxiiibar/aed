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
	// Iteramos sobre el map
	for (const auto& pair : mymap) {
		std::cout << "Clave: " << pair.first << " -> Valores: ";
		// Iteramos sobre la lista asociada a la clave
		for (const auto& value : pair.second) {
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}

void merge(list<int> &L1, list<int> &L2, list<int>& L){
	auto it1=L1.begin();auto it2=L2.begin();
	while((it1!=L1.end())and(it2!=L2.end())){
		if(*it1<*it2){
			L.push_back(*it1);
			it1++;
		}
		else{
			L.push_back(*it2);
			it2++;
		}
	}
	if(it1!=L1.end())L.insert(L.end(),it1,L1.end());
	if(it2!=L2.end())L.insert(L.end(),it2,L2.end());
	L.sort();
}
	
void merge_map(map<int, list<int>> &A, map<int, list<int>> &B, map<int, list<int>> &C){
	bool condicion = true;
	for (const auto& pair : A) {
		for (const auto& pair2 : B){
			if(pair.first == pair2.first){
				list<int>D;
				list<int>Primero = pair.second;
				list<int>Segundo = pair2.second;
				merge(Primero, Segundo, D);
				condicion = false;
				C.insert({pair.first, D});
			}
		}
		if(condicion)C.insert(pair);
		condicion=true;
	}
	for (const auto& pair: B){
		if(C.find(pair.first) == C.end()) C.insert(pair);
	}
}

int main() {
	
	map<int, list<int>> A = {{1,{1,2,3}},{2,{19,28,37}},{3,{17,26,35}}};
	map<int, list<int>> B = {{1,{4,5,6}},{2,{7,12,13}},{4,{12,32,43}}};
	map<int, list<int>> C;
	
	merge_map(A,B,C);
	
	show_map_of_lists(C);
	
	return 0;
}
