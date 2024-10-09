#include <iostream>
#include <list>
#include <vector>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void ascendente2(list<int> &L, vector<list<int>> &VL){

}

int main() {
	list<int>L = {1,2,3,4,5,6,7,1,2,3,8,9,12,1,2,3,2,3,4};
	vector<list<int>> VL;
	show_list(L);
	ascendente2(L, VL);
	for(unsigned int i=0;i<VL.size();i++) { 
		show_list(VL[i]);
	}
	return 0;
}
