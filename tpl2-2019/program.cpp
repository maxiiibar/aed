#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;

void step_fill_ordprev(tree<int> &T,list<int> &L, tree<int>::iterator it){
  if(it == T.end()) return;
  auto itL = L.begin();
  if(itL == L.end()) return;
  (*it) = *itL;
  L.erase(itL);
  it = it.lchild();
  while (it != T.end()) step_fill_ordprev(T, L, it++);
}

void fill_ordprev(tree<int> &T,list<int> &L) {
  auto it = T.begin();
  step_fill_ordprev(T, L, it);
}


void step_a_lo_ancho(graph& G, tree<char>& T, tree<char>::iterator itTree, list<char>&visitados, graph::iterator itGraph, tree<char>::iterator itPadre, list<char>L){
  if(itGraph == G.end()) return;
  if(itTree != T.begin()){
    for(auto elem : itGraph -> second){
      if(elem == *itPadre /*and find(L.begin(), L.end(), elem) != L.end()*/) return;
    }
  }
  if(find(visitados.begin(), visitados.end(), itGraph -> first) != visitados.end()) return;
  auto it = itTree.lchild();
  while(it != T.end()) it++;
  it = T.insert(it, itGraph -> first);
  visitados.push_back(itGraph -> first);
  auto itList = (itGraph -> second).begin();
  while (itList != (itGraph -> second).end()){
    auto newList = itGraph -> second;
    newList.remove(*itList);
    step_a_lo_ancho(G, T, it, visitados, G.find(*itList), itTree, newList);
    itList++;
  }
}

void a_lo_ancho(graph& G, tree<char>& T){
  auto it = G.begin();
  list<char>visitados;
  T.insert(T.begin(), it -> first);
  visitados.push_back(it -> first);
  auto itList = (it -> second).begin();
  while (itList != (it -> second).end()){
    step_a_lo_ancho(G, T, T.begin(),visitados, G.find(*itList), T.begin(), visitados);
    itList++;
  }
}

//void step_a_lo_ancho(graph& G, graph::iterator itGraph, tree<char>& T, tree<char>::iterator itTree, list<char>&visitados){
//  if(itGraph == G.end()) return;
//  if(find(visitados.begin(), visitados.end(), itGraph -> first) != visitados.end());
//  itTree = T.insert(itTree, itGraph -> first);
//  visitados.push_back(itGraph -> first);
//  itTree = itTree.lchild();
//  while(itTree != T.end()) itTree++;
//  auto it = (itGraph -> second).begin();
//  while(it != (itGraph -> second).end())step_a_lo_ancho(G, G.find(*(it++)), T, itTree, visitados);
//}
//  
//void a_lo_ancho(graph& G, tree<char>& T){
//    list<char>visitados;
//    step_a_lo_ancho(G, G.begin(), T, T.begin(), visitados);
//}
void intersect_map(map<int,list<int>> &A, map<int,list<int>> &B,map<int,list<int>> &C){
  // COMPLETAR AQUI...
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

int main() {

  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  cout << "seed: 123" << endl;
  do {
    ev.eval<1>(fill_ordprev,vrbs);
    h1 = ev.evalr<1>(fill_ordprev,seed,vrbs);

    ev.eval<2>(a_lo_ancho,vrbs);
    h2 = ev.evalr<2>(a_lo_ancho,seed,vrbs);
    
    ev.eval<3>(intersect_map,vrbs);
    h3 = ev.evalr<3>(intersect_map,seed,vrbs);
    
    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    cout << endl << "Siguiente seed: ";
  } while (cin>>seed);

  return 0;
}
