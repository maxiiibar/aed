#include <iostream>
#include <list>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void invert(list<int> &L){
	auto itB = L.begin();
	auto itE = L.end();
	auto itAux = itB;
	itE--;
	while(itB!=itE){
		int aux = *itB;
		int aux2 = *itE;
		*itB = aux2;
		*itE = aux;
		itAux = itB;
		itB++;
		itE--;
		if(itE == itAux){
			break;
		}
	}
}

int main() {
	list<int>L = {1,2,3,4,5,6};
	show_list(L);
	invert(L);
	show_list(L);
	return 0;
}
