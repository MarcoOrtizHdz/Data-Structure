#include <iostream>
#include <vector>
#include "Priority.h"

using namespace std;

int main() {
  Priority p1;

  /*p1.add(1);
  p1.add(2);
  p1.add(3);*/

  p1.push(22);
  p1.push(4);
  p1.push(10);
  p1.push(15);
  p1.push(2);
  p1.push(40);
  p1.push(7);
  p1.print();

  cout << "\nTop: " << p1.top() << "\nSize: " << p1.size() << endl;
  cout << (p1.empty() ? "Vacio" : "Lleno");

  /*p1.pop();
  cout << "\n\nDespués del pop" << endl;
  p1.print();*/

  p1.push(17);
  cout << "\nDespues del push 17" << endl;
  p1.print();
  p1.push(38);
  cout << "\nDespues del push 38" << endl;
  p1.print();

  return 0;
}
