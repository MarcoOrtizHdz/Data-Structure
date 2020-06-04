#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>

class stack{
  public:
    stack();
    ~stack();
    void push(T data);
    void pop();
    T top();
    bool empty();
    int size();

  private:
    Node<T> *tope;
    int tam;
};

template <class T>
stack<T>::stack() {
  tope = NULL;
  tam = 0;
}

template <class T>
stack<T>::~stack() {
  Node<T> *aux = tope;
  while (aux != NULL){
    tope=tope->getNext();
    delete aux;
    aux = tope;
  }
}

template <class T>
void stack<T>::push(T data) {
  tope = new Node<T>(data, tope);
  tam++;
}

template <class T>
void stack<T>::pop() {
  Node<T> *aux = tope;
  tope = tope->getNext();
  delete aux;
  tam--;
}

template <class T>
T stack<T>::top() {
  return tope->getData();
}

template <class T>
int stack<T>::size() {
  return tam;
}

template <class T>
bool stack<T>::empty() {
  return ( tope == NULL);
}

#endif // STACK_H_INCLUDED
