#include <list>
#include <iostream>
using namespace std;

void show_list(list<int> &L)
{
	auto it = L.begin();
	auto element = L.begin();
	int contador = 0;
	while(it != L.end()){
		element = it;
		cout <<"Elemento "<<contador<<": "<<*it<<endl;
		auto aux = element;
		while(element != L.end()){
			if(*element<*aux){
				aux = element;
			}
			element++;
		}
		int auxInt = *element;
		cout << auxInt <<endl;
		*element = *aux;
		*aux= auxInt; 
		it++;
		contador++;
	}
	