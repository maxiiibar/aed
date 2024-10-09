#include <list>#include <iostream>using namespace std;void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}void basic_sort(list<int> &L) {
	list<int>L2;
	auto it = L.begin();
	auto aux = L.begin();
	while(!L.empty()){
		it = L.begin();
		aux = L.begin();
		
		while(it != L.end()){
			
			if(*it<*aux){
				aux = it;
			}
			it++;
			
		}
		L2.push_back(*aux);
		L.erase(aux);
	}
	L.swap(L2);}int main(void){	list<int> L = {4,2,6,1,3,5};	show_list(L);		basic_sort(L);	show_list(L);	}
