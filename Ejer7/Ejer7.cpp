#include <iostream>
#include <list>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void ascendente1(list<int> &L, list<list<int>> &LL){
	auto it = L.begin();
	int aux = 0;
	list<int> A;
	while(it!=L.end()){
		if((*it)>aux){
			aux=(*it);
			A.push_back(aux);
		} else{
			LL.push_back(A);
			aux=*it;
			A.erase(A.begin(), A.end());
			A.push_back(aux);
		}
		it++;
	}
	LL.push_back(A);
}

int main() {
	list<int>L = {1,2,3,4,5,6,7,1,2,3,8,9,12,1,2,3,2,3,4};
	list<list<int>> LL;
	show_list(L);
	ascendente1(L, LL);
	for( list<list<int>>::iterator it=LL.begin(); it!=LL.end(); ++it ) { 
		show_list(*it);
	}
	return 0;
}
