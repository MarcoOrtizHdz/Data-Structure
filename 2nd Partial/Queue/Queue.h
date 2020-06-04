#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "Node.h"

template <class T>

class queue {
  public:
    queue();
    ~queue();

    void push(T data);
    void pop();
    T front();
    bool empty();
    int size();

  private:
    Node<T> *final;
    int tam;
};

template <class T>
queue<T>::queue() {
  final = NULL;
  tam = 0;
}

template <class T>
queue<T>::~queue() {
  if ( final != NULL ) {
    //Se quita la circularidad
    Node<T> *aux = final->getNext();
    final->setNext(NULL);
    final = aux;
    //Se borra todo el queue como si fuera LinkedList
    while ( final != NULL ) {
      final = final->getNext();
      delete aux;
      aux = final;
    }
  } 
}

template <class T>
void queue<T>::push(T data) {
  if (final == NULL) {
    final = new Node<T>(data);
    final->setNext(final);
  }
  else {
    final->setNext(new Node<T>(data, final->getNext() ));
    final = final->getNext();
  }
  tam++;
}

template <class T>
void queue<T>::pop() {
  Node<T> *aux = final->getNext();
  if (aux == final){
    final = NULL;
  }
  else {
    final->setNext(aux->getNext());
  }
  delete aux;
  tam--;
}

template <class T>
T queue<T>::front() {
  return final->getNext()->getData();
}

template <class T>
int queue<T>::size() {
  return tam;
}

template <class T>
bool queue<T>::empty() {
  return ( final == NULL );
}

#endif // QUEUE_H_INCLUDED
