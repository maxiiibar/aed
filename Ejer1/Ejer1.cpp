#include <list>
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
	L.swap(L2);