#include <iostream>
#include "BST.h"

using namespace std;

int main() {
  BST arbol;
  BST arbol2;
  arbol.add(20);
  arbol.add(14);
  arbol.add(25);
  arbol.add(10);
  arbol.add(18);
  arbol.add(17);
  arbol.add(28);
  arbol.add(27);
  arbol.add(30);
  arbol.add(19);
  arbol2.add(20);
  arbol2.add(14);
  arbol2.add(25);
  arbol2.add(10);
  arbol2.add(18);
  arbol2.add(17);
  arbol2.add(28);
  arbol2.add(27);
  arbol2.add(30);
  arbol2.add(19);
  cout << "\nPreorder: ";
  arbol.print(1);
  cout << "Indorder: ";
  arbol.print(2);
  cout << "Postorder: ";
  arbol.print(3);
  cout << "Hojas: ";
  arbol.print(4); 
  cout << "\nAncestros de 17: ";
  arbol.ancestors(17);
  cout << "\nWhat level am i? (Number 30): ";
  cout << arbol.whatLevelAmI(30) << endl;
  cout << "Tree Height: " << arbol.height() << endl;
  cout << "Nivel por Nivel: ";
  arbol.print(5);
  cout << "Nearest Relative (10 y 19): ";
  cout << arbol.nearestRelative(10, 19);
  cout << "\n\nArbol 1: ";
  arbol.print(2);
  cout << "Arbol 2: ";
  arbol2.print(2);
  cout << "== mio" << endl;
  if (arbol==arbol2) {
    cout << "Los arboles son iguales " << endl;
  } else {
    cout << "Los arboles son diferentes " << endl;
  }
  cout << "== del profe" << endl;
  if (arbol==arbol2) {
    cout << "Los arboles son iguales " << endl;
  } else {
    cout << "Los arboles son diferentes " << endl;
  }
  cout << "\nPara testear el mirror " << endl;
  cout << "Antes ";
  arbol.print(2);
  arbol.mirror();
  cout << "Despu ";
  arbol.print(2);
  cout << "\nPara testear el copy constructor" << endl;
  BST arbol3(arbol);
  cout << "Arbol 1: ";
  arbol.print(2);
  cout << "Arbol 3: ";
  arbol3.print(2);
  cout << "\nMax Width: " << arbol.maxWidth() << endl;
}
