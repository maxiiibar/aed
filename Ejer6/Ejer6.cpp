#include <iostream>
#include <list>
using namespace std;

void show_list(list<int> &L){	for (auto x : L)	{		cout << x <<", ";	}	cout << endl;}

void reemplaza(list<int> &L, list<int> &SEQ, list<int> &REEMP){
	auto itL = L.begin();
	auto auxL = L.begin();
	auto itSEQ = SEQ.begin();
	bool cond = true;
	while(itL!=L.end()){
		if((*itL)==(*itSEQ)){
			for(unsigned int i=1;i<SEQ.size();i++) { 
				itL++; itSEQ++;
				if((*itL)!=(*itSEQ)){
					cond = false;
				}
				if (!cond) break;
			}
			if(cond){
				itL++;
				itL=L.erase(auxL, itL);
				L.insert(itL, REEMP.begin(), REEMP.end());
			}
		}
		itL++;
		itSEQ = SEQ.begin();
		auxL=itL;
	}
}

int main() {
	list<int>L = {1,2,3,4,5,6,7,1,2,3,8,9,12,1,2,3};
	list<int>S = {1,2,3};
	list<int>R = {4,5,6,7};
	show_list(L);
	reemplaza(L,S,R);
	show_list(L);
	return 0;
}
