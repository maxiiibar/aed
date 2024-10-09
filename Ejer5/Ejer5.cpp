#include <iostream>
#include <list>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void junta(list<int> &L, int c){
	auto it = L.begin();
	int suma=0,cont=0;
	while(it!=L.end()){
		if(cont<c){
			suma+=(*it);
		}else{
			L.insert(it,suma);
			suma=0; cont=0;
			suma+=(*it);
		}
		cont++;
		it=L.erase(it);
	}
	if(suma!=0)L.insert(L.end(),suma);
}

int main() {
	list<int>L = {1,2,3,4,5,6,7};
	show_list(L);
	junta(L, 4);
	show_list(L);
	return 0;
}
