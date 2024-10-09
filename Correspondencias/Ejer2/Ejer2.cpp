#include <iostream>
#include <map>
#include <list>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void show_map(const std::map<int, int> &M) {
	for (const auto& pair : M) {
		std::cout << "Clave: " << pair.first << ", Valor: " << pair.second << std::endl;
	}
}

void map2list(map<int, int> &M, list<int> &Keys, list<int> &Vals){
	for (const auto& pair : M) {
		Keys.push_back(pair.first);
		Vals.push_back(pair.second);
	}
}
	

void list2map(map<int, int> &M, list<int> &Keys, list<int> &Vals){
	auto it = Keys.begin();
	auto it2 = Vals.begin();
	while(it != Keys.end()){
		if(it2 != Vals.end()){
			M[*it]=*it2;
			++it2;
		}
		else if (M.count(*it) != 1) M[*it]=0;
		it++;
	}
}

int main() {
	
	list<int>Keys = {1,2,3,4,5,1,2,0,9}, Vals = {6,7,8,9};
	show_list(Keys);
	show_list(Vals);
	map<int,int>M;
	
	cout<<endl;
	list2map(M, Keys, Vals);
	
	show_map(M);
	
	return 0;
}
