#include <iostream>
#include <map>
#include <list>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void map2list(map<int, int> &M, list<int> &Keys, list<int> &Vals){
	for (const auto& pair : M) {
		Keys.push_back(pair.first);
		Vals.push_back(pair.second);
	}
}

int main() {
	
	map<int, int>M = {{1, 4}, {2, 5}, {3, 6}};
	list<int>Keys, Vals;
	
	map2list(M, Keys, Vals);
	
	show_list(Keys);
	show_list(Vals);
	
	return 0;
}
