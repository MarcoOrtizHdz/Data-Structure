#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  stack<string> miPila;

  miPila.push("AAAAA");
  miPila.push("BBBBB");
  miPila.push("CCCCC");

  cout << "Total de datos antes del pop: " << miPila.size() << endl;  

  //Para mostrar todos los elementos del stack
  while ( !miPila.empty() ) {
    cout << miPila.top() << endl;
    miPila.pop(); //Se popea para que no muestre siempre el primero
  }

  cout << "Total de datos despues del pop: " << miPila.size() << endl;

  return 0;
}
