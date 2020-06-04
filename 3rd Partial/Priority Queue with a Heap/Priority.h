#include <iostream>
#include <vector>

using namespace std;

class Priority
{
  public: 
    Priority();
    Priority(bool p);
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
    void print(); //Para testear
    bool checa(int dir);

  private:
    vector<int> contenedor;
    bool prioridad;
    int tam;
};

Priority::Priority() {
  contenedor.assign(101, 0);
  prioridad = true;
  tam = 0;
}

Priority::Priority(bool p) {
  contenedor.assign(101, 0);
  prioridad = p;
  tam = 0;
}

void Priority::push(int data){
  contenedor[++tam] = data;
  int dir = tam;
  //while(dir != 1 && contenedor[dir/2]<contenedor[dir]) {
  while(dir != 1 && checa(dir)) {
    int aux = contenedor[dir/2];
    contenedor[dir/2]=contenedor[dir];
    contenedor[dir]=aux;
    dir/=2;
  }
}

bool Priority::checa(int dir) {
  if (prioridad) {
    return (contenedor[dir/2] < contenedor[dir]);
  }
  else {
    return (contenedor[dir/2] > contenedor[dir]);
  }
}

void Priority::pop() {
  contenedor[1] = contenedor[tam];
  contenedor[tam] = 0;
  tam--;
  int curr = 1;
  
  if (prioridad) {
    while (contenedor[curr] < contenedor[2*curr] || contenedor[curr] < contenedor[(2*curr)+1])
    {
      if (contenedor[curr] < contenedor[2*curr]) {
        int aux = contenedor[2*curr];
        contenedor[2*curr] = contenedor[curr];
        contenedor[curr] = aux;
        curr = 2*curr;
      }
      else if (contenedor[curr] < contenedor[(2*curr)+1]) {
        int aux = contenedor[(2*curr)+1];
        contenedor[(2*curr)+1] = contenedor[curr];
        contenedor[curr] = aux;
        curr = (2*curr)+1;
      }
    }
  }

  else {
    while (contenedor[curr] > contenedor[2*curr] || contenedor[curr] > contenedor[(2*curr)+1])
    {
      if (contenedor[curr] > contenedor[2*curr]) {
        int aux = contenedor[2*curr];
        contenedor[2*curr] = contenedor[curr];
        contenedor[curr] = aux;
        curr = 2*curr;
      }
      else if (contenedor[curr] > contenedor[(2*curr)+1]) {
        int aux = contenedor[(2*curr)+1];
        contenedor[(2*curr)+1] = contenedor[curr];
        contenedor[curr] = aux;
        curr = (2*curr)+1;
      }
    }
  }
}

int Priority::top() {
  return contenedor[1];
}

int Priority::size() {
  return tam;
}

bool Priority::empty() {
  return (tam == 0);
}

void Priority::print() {
  for (int i=1; i<=tam; i++) {
    cout << contenedor[i] << " ";
  }
}
