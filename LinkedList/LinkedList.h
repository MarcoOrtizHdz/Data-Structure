#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedList {
  public:
    LinkedList();
    ~LinkedList();

    int getSize();
    bool isEmpty();
    void print();

    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    
    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();

    T get(int pos);
    T set(int pos, T data);
    bool change(int pos1, int pos2);

    void reverse();
    bool operator==(const LinkedList<T> &LL);
    void operator+=(T data);
    void operator+=(const LinkedList<T> &LL);
    LinkedList<T>(const LinkedList<T> &LL);
    void operator=(const LinkedList<T> &LL);

  private:
    Node<T> *head;
    int size;
    void deleteHelper();
};

template <class T>
LinkedList<T>::LinkedList(){
  head = NULL; //nullptr;
  size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
  deleteHelper();  
}

template <class T>
int LinkedList<T>::getSize(){
  return size;
}

template <class T>
bool LinkedList<T>::isEmpty(){
  return (head == NULL);
}

template<class T>
void LinkedList<T>::print(){
  Node<T> *curr = head;
  for (int i=0; i<size; i++){
    cout << curr->getData() << " ";
    curr = curr->getNext();
  }
  cout << endl;
}

template <class T>
void LinkedList<T>::addFirst(T data){
  head = new Node<T>(data, head);
  size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
  if( this->isEmpty() ){
    addFirst(data);
  }
  else{
    Node<T> *curr = head;
    while (curr->getNext() != NULL)
    {
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data));
    size++;
  }
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
  if (pos > size){
    return false;
  }
  if (pos == 0){
    addFirst(data);
  }
  else if (pos == size){
    addLast(data);
  }
  else{
    Node<T> *curr = head;
    for (int i=1; i<pos; i++)
    {
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data, curr->getNext()));
    size++;
  }
  return true;
}

template <class T>
void LinkedList<T>::deleteFirst(){
  if ( !this->isEmpty() )
  {
    Node<T> *curr = head; //nuevo nodo que apunta a la primera posición para no perder el valor de la primera posición
    head = head->getNext(); //se usa -> y no .getNext porque head es un apuntador y no un Nodo
    delete curr; //se borra el valor de la primera posición para que no se quede guardado en la memoria
    size--; //como se borró la primera posición, el size baja
  }
}

template <class T>
void LinkedList<T>::deleteLast(){
  if (size <= 1)
  {
    deleteFirst();
  }
  else
  {
    Node<T> *curr = head;
    while ( curr->getNext()->getNext() != NULL)
    {
      curr = curr->getNext();
    }
    delete curr->getNext();
    curr->setNext(NULL);
    size--;
  }
}

template <class T>
void LinkedList<T>::del(int pos){
  if (pos<size) // El size puede ser 1 pero está en la posición 0
  {
    if (pos == 0) //Si quiere borrar la primera posición
    {
      deleteFirst();
    }
    else if (pos == size-1) //Si quiere borrar el último
    {
      deleteLast();
    }
    else
    {
      Node<T> *curr = head;
      for (int i=1; i<pos; i++)
      {
        curr = curr->getNext();
      }
      Node<T> *temp = curr->getNext();
      curr->setNext(temp->getNext());
      delete temp;
      size--;
    }
  }
}

template <class T>
int LinkedList<T>::deleteAll(){
  int cant=size;
  deleteHelper();
  size=0;
  return cant;
}

template <class T>
void LinkedList<T>::deleteHelper(){
  Node<T> *curr = head;
  while ( !this->isEmpty() ) //head != NULL
  {
    head = head->getNext();
    delete curr;
    curr = head;
  }
}

template <class T>
T LinkedList<T>::get(int pos){
  Node<T> *curr = head;
  for(int i=0; i<pos; i++){
    curr = curr->getNext();
  }
  return curr->getData();
}

template <class T>
T LinkedList<T>::set(int pos, T data){
  Node<T> *curr = head;
  for (int i=0; i<pos; i++){
    curr = curr->getNext();
  }
  T temp = curr->getData();
  curr->setData(data);
  return temp;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2){
  if (pos1 == pos2){
    return true;
  }

  int posMay = (pos1 > pos2 ? pos1 : pos2);
  // (si pos1 > pos2 then posMay=pos1 : else posMay=pos2)
  int posMen = (pos1 < pos2 ? pos1 : pos2);
  // (si por1 < pos2 then posMen=pos1 : else posMen=pos2)

  Node<T> *curr = head;
  for (int i=0; i<posMen; i++){
    curr = curr->getNext();
  }
  Node<T> *curr2 = curr;
  for (int i = posMen; i<posMay; i++){
    curr2 = curr2->getNext();
  }

  T temp = curr->getData();
  curr->setData(curr2->getData());
  curr2->setData(temp);

  return true;
}

//------------------- PARA LA TAREA -------------------

template <class T> //miLista.reverse()
void LinkedList<T>::reverse(){
  Node <T> *curr = head;
  Node <T> *ant = NULL;
  Node <T> *sig = NULL;

  if (size>1){
    while (curr != NULL){
      sig = curr->getNext();
      curr->setNext(ant);
      ant = curr;
      curr = sig;
    }
    head = ant;
  }
}

template <class T> // if (miLista1 == mmiLista2)
bool LinkedList<T>::operator==(const LinkedList<T> &LL){
  if (this->size != LL.size){
    return false;
  }
  else{
    Node <T> *curr = this->head;
    Node <T> *comp = LL.head;

    while (curr!=NULL){
      if (curr->getData() != comp->getData()){
        return false;
      }

      else{
        curr = curr->getNext();
        comp = comp->getNext();
      }
    }
    return true;
  }
}

template <class T> // miLista += "CARO"
void LinkedList<T>::operator+=(T data){
  if (this->isEmpty()){
    addFirst(data);
  }
  else{
    Node<T> *curr = head;
    while (curr->getNext()!=NULL){
      curr = curr->getNext();
    }
    curr->setNext(new Node<T> (data));
    size++;
  }
}

template <class T> // miLista += otraLista
void LinkedList<T>::operator+=(const LinkedList<T> &LL){
  Node<T> *curr1 = head;
  Node<T> *curr2 = LL.head;

  if(this->isEmpty()){
    addFirst(curr2->getData());
    curr2 = curr2->getNext();
    curr1 = head;
  }

  while(curr1->getNext() != NULL){
    curr1 = curr1->getNext();
  }

  while(curr2!=NULL){
    curr1->setNext(new Node<T> (curr2->getData()));
    curr1 = curr1->getNext();
    curr2 = curr2->getNext();
    size++;
  }
}

template <class T> // LinkedList<string> nueva(miLista)
LinkedList<T>::LinkedList(const LinkedList<T> &LL){
  Node<T> *curr2 = LL.head;
  head = new Node<T>(curr2->getData(), NULL);
  size = 1;
  Node<T> *curr = head;

  while (curr2->getNext()!=NULL){
    curr2 = curr2->getNext();
    curr->setNext(new Node<T>(curr2->getData(), NULL));
    curr = curr->getNext();
    size++;
  }
}

template <class T> // miLista1 = miLista2
void LinkedList<T>::operator=(const LinkedList<T> &LL){
  deleteHelper();

  if(LL.size==0){
    head=NULL;
    size=0;
  }
  else{
    Node<T> *curr2 = LL.head;
    head=new Node<T>(curr2->getData(), NULL);
    Node<T> *curr = head;
    size = 1;

    while(curr2->getNext()!=NULL){
      curr2 = curr2->getNext();
      curr->setNext(new Node<T>(curr2->getData(), NULL));
      curr = curr->getNext();
      size++;
    }
  }
}

#endif // LINKEDLIST_H_INCLUDED
