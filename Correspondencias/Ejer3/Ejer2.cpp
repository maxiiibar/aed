#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void show_map(const std::map<int, int> &M) {
	for (const auto& pair : M) {
		std::cout << "Clave: " << pair.first << ", Valor: " << pair.second << std::endl;
	}
}

bool areinverse(map<int,int> &M1, map<int,int> &M2){
	for (const auto& pair : M1) {
		auto it = M2.find(pair.second);
		if (it == M2.end() || it->second != pair.first) {
			return false;
		}
	}
	return true;
}

int main() {
	
	map<int, int> M1 = {{1, 2},{3, 4},{5, 6}};
	map<int, int> M2 = {{2, 1},{4, 3},{6, 5}};
	
	cout<<areinverse(M1, M2);
	
	return 0;
}
