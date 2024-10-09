#include <list>
#include <iostream>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

list<int> concatA(list<int>&L1, list<int>&L2){
	auto nuevaLista = L1;
	auto it = L2.begin();
	while (it != L2.end()){
		nuevaLista.insert(nuevaLista.end(), *it);
		it++;
	}
	
	return nuevaLista;
}

list<int> concatB(list<list<int>> &LL){
	auto it = LL.begin();
	auto list = *it;
	it++;
	while (it != LL.end()){
		list.insert(list.end(), (*it).begin(), (*it).end());
		it++;
	};
	return list;
}
	
	
list<int> concatBprima(list<list<int>>&LL){
	auto it = LL.begin();
	auto list = *it;
	it++;
	while (it != LL.end()){
		list.splice(list.end(), *it);
		it++;
	};
	return list;
}

int main() {
	list<int> L1 = {1,2,3,4};
	list<int> L2 = {5,6,7,8};
	list<int> L3 = {9,10,11,12};
	list<list<int>> listas = {L1,L2,L3};
		auto lista = concatA(L1,L2);
	auto lista2 = concatBprima(listas);
		show_list(lista2);
	show_list(L1);
	
	return 0;
}
