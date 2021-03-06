// Recorrido de DFS, con Lista Adj

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void leeListAdj(vector<vector<int> > &listAdj, int e) {
  int a, b;
  for (int i=1; i<=e; i++) {
    cin >> a >> b;
    listAdj[a-1].push_back(b-1);
    listAdj[b-1].push_back(a-1);
  }
}

void printListAdj(vector<vector<int> > &listAdj) {
  // Es el size del primer vector
  for (int i=0; i<listAdj.size(); i++) {
    cout << (i+1) << " : ";
    // Es el size de cada uno de los vectores del vector, tiene un size diferente
    for (int j=0; j<listAdj[i].size(); j++) {
      cout << "->" << (listAdj[i][j]+1);
    }
    cout << endl;
  }
}

void DFS(vector<vector<int> > &listAdj) {
  stack<int> pila;
  pila.push(0);
  int data;
  vector<bool> status(listAdj.size(), false);
  while ( !pila.empty() ) {
    data = pila.top();
    pila.pop();
    if ( !status[data] ) {
      cout << (data+1) << " ";
      status[data] = true;
      for (int i=listAdj[data].size()-1; i>=0; i--) {
        if ( !status[listAdj[data][i]]) {
          pila.push(listAdj[data][i]);
        }
      }
    }
  }
  cout << endl;
}

int main() {
  // v = Nodos (Vertex), e = Arcos (Edges)
  int v, e;  
  cin >> v >> e;
  vector< vector<int> > listAdj(v);
  leeListAdj(listAdj, e);
  //printListAdj(listAdj);
  DFS(listAdj);
}
