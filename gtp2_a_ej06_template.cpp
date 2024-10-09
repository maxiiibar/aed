#include <iostream>
#include <list>
using namespace std;


template<class T>
void show_list(list<T>& L){
	cout<<"(";
	for(typename list<T>::iterator it = L.begin();it!=L.end();it++){
		cout<<*it<<" ";		
	}
	cout<<")";
}


void reemplaza(list<int> &L, list<int>& SEQ, list<int> &REEMP){			
	auto itL = L.begin();
	auto itS = SEQ.begin();
	while(itL != L.end()){
		while(itS != SEQ.end()){
			if(*itL == *itS){
				itS++;
			}
			else{
				itS = SEQ.begin();
			}
			itL++;
		}
		
	}
}

int main() {
	list<int> L = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int> SEQ = {4,5,1};
	list<int> REEMP = {9,7,3};
	reemplaza(L, SEQ, REEMP);
	
	show_list(L);
	return 0;
}
