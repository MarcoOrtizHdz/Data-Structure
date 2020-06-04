#include <iostream>
#include "queue.h"

using namespace std;

int main() {
  queue<string> miFila;
  miFila.push("A");
  miFila.push("B");
  miFila.push("C");

  cout << "Total de datos: " << miFila.size() << endl;

  while ( !miFila.empty() ) {
    cout << miFila.front() << endl;
    miFila.pop();
  }

  cout << "Total de datos: " << miFila.size() << endl;

  return 0;
}
