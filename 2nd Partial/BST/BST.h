#include "NodeT.h"
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class BST 
{
  public:
    BST();
    ~BST();
    BST(const BST &otro);
    void add(int data);
    bool search(int data);
    void remove(int data);
    void print(int c);
    int count();
    int height();
    void ancestors(int data);
    int whatLevelAmI(int data);
    void mirror();
    int nearestRelative(int uno, int dos);
    //bool operator==(const BST &otra); //mio
    bool operator==(const BST &otro); //Del profe
    int maxWidth();

  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r); 
    void preOrder(NodeT *r); 
    void inOrder(NodeT *r); 
    void postOrder(NodeT *r); 
    void liberar(NodeT *r);
    void printLeaves(NodeT *r);
    void NivelxNivel(NodeT *r);
    int cuenta(NodeT *r);
    int route(NodeT *r);
    void voltear(NodeT *r);
    //bool checa(NodeT *curr1, NodeT *curr2); //mio
    bool checkPreorder(NodeT *uno, NodeT *dos); //Del profe
    NodeT* copyPreorder(NodeT *r);
};

BST::BST() {
  root = NULL;
}

BST::~BST() {
  liberar(root);
}

BST::BST(const BST &otro) {
  root=copyPreorder(otro.root);
}

NodeT* BST::copyPreorder(NodeT *r) {
  if(r==NULL) {
    return NULL;
  }
  NodeT* curr = new NodeT(r->getData());
  curr->setLeft(copyPreorder(r->getLeft()));
  curr->setRight(copyPreorder(r->getRight()));
  return curr;
}

void BST::add(int data) {
  NodeT *father = NULL;
  NodeT *curr = root;
  
  while ( curr != NULL ) {
    father = curr;

    if (curr->getData() == data) {
      return;
    }
    curr = ( curr->getData() > data ? curr->getLeft() : curr->getRight() );
  }

  if (father == NULL) {
    root = new NodeT(data);
  }
  else {
    if (father->getData() > data) {
      father->setLeft(new NodeT(data));
    }
    else {
      father->setRight(new NodeT(data));
    }
  }
}

bool BST::search(int data) {
  NodeT *curr = root;
  while ( curr != NULL ) {
    if (curr->getData() == data ) {
      return true;
    }
    curr = ( curr->getData() > data ? curr->getLeft() : curr->getRight() );
  }
  return false;
}

int BST::howManyChildren(NodeT *r) {
  int cont=0;
  if (r->getLeft() != NULL ) {
    cont++;
  }
  if (r->getRight() != NULL ) {
    cont++;
  }
  return cont;
}

int BST::pred(NodeT *r) {
  NodeT *curr = r->getLeft();
  while(curr->getRight() != NULL) {
    curr = curr->getRight();
  }
  return curr->getData();
}

int BST::succ(NodeT *r) {
  NodeT *curr = r->getRight();
  while(curr->getLeft() != NULL) {
    curr = curr->getLeft();
  }
  return curr->getData();
}

void BST::remove(int data) {
  NodeT *curr = root;
  NodeT *father = NULL;
  while (curr != NULL && curr->getData() != data) {
    father = curr;
    curr = (curr->getData() > data) ? 
            curr->getLeft() : curr->getLeft(); 
  }
  if(curr == NULL) {
    return;
  }
  int c = howManyChildren(curr);

  switch(c) {
    case 0: //Si tiene 0 hijos
        if (father == NULL) {
          root = NULL;
        }
        else {
          if (father->getData() > data) {
            father->setLeft(NULL);
          }
          else {
            father->setRight(NULL);
          }
        }
        delete curr;
        break;

    case 1: //Si tiene 1 hijo
        if (father == NULL) {
          if (curr->getLeft() != NULL) {
            root = curr->getLeft();
          }
          else {
            root = curr->getRight();
          }
        } 
        else { //Si Father no es NULL
          if (father->getData() > data) { //Caso estoy a la Izq del padre
            if (curr->getLeft() != NULL) { //Caso estoy a la Izq del padre y mi hijo está a mi Izq
              father->setLeft(curr->getLeft());
            }
            else { //Caso estoy a la Izq del padre y mi hijo está a mi Der
              father->setLeft(curr->getRight());
            }
          }
          else { //Caso estoy a la Der del padre
            if (curr->getLeft() != NULL) { //Caso estoy a la Der del padre y mi hijo está a mi Izq
              father->setRight(curr->getLeft());
            }
            else { //Caso estoy a la Der del padre y mi hijo está a mi Der
              father->setRight(curr->getRight());
            }
          }
        }
        delete curr;
        break;

    case 2:
        int x = succ(curr);
        remove(x);
        curr->setData(x);
        break;
  }
}

void BST::preOrder(NodeT *r) {
  if ( r != NULL ) {
    cout << r->getData() << " ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
  }
}

void BST::inOrder(NodeT *r) {
  if ( r != NULL ) {
    inOrder(r->getLeft());
    cout << r->getData() << " ";
    inOrder(r->getRight());
  }
}

void BST::postOrder(NodeT *r) {
  if ( r != NULL ) {
    postOrder(r->getLeft());
    postOrder(r->getRight());
    cout << r->getData() << " ";
  }
}

void BST::liberar(NodeT *r) {
  if ( r != NULL ) {
    liberar(r->getLeft());
    liberar(r->getRight());
    delete r;
  }
}

void BST::printLeaves(NodeT *r) {
  if ( r != NULL ) {
    if ( r->getLeft() == NULL && r->getRight() == NULL ) {
      cout << r->getData() << " ";
    }
    printLeaves( r->getLeft() );
    printLeaves( r->getRight() );
  }
}

void BST::NivelxNivel(NodeT *r) {
  queue<NodeT*> q;

  if (r!=NULL) {
    q.push(r);
    while (!q.empty()) {
      cout << q.front()->getData() << " ";
      if (q.front()->getLeft()!=NULL) {
        q.push(q.front()->getLeft());
      }
      if (q.front()->getRight()!=NULL) {
        q.push(q.front()->getRight());
      }
      q.pop();
    }
  }
}

void BST::print(int c) {
  switch(c) {
    case 1: preOrder(root);
            break;
    case 2: inOrder(root);
            break;
    case 3: postOrder(root);
            break;
    case 4: printLeaves(root);
            break;
    case 5: NivelxNivel(root);
            break;
  }
  cout << endl;
}

int BST::count() {
  return cuenta(root);
}

int BST::cuenta(NodeT *r) {
  if ( r != NULL ) {
    return 1 + cuenta( r->getLeft() ) + cuenta( r->getRight() );
  }
  else {
    return 0;
  }
}

int BST::height() {
  return route(root);
}

int BST::route(NodeT *r) {
  int izq=0; int der=0;

  if (r!=NULL) {
    izq++;
    der++;
    izq += route(r->getLeft());
    der += route(r->getRight());
  }
  return (izq > der ? izq : der);
}

void BST::ancestors(int data) {
  NodeT *curr = root;
  stack <int> s;

  while (curr != NULL ) {
    s.push(curr->getData());
    if (curr->getData() == data) {
      s.pop();
      if (s.empty()) {
        cout << "No tiene ancestros ";
      }
      while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
      }
    }
    if (curr->getData() > data) {
      curr = curr->getLeft();
    }
    else {
      curr = curr->getRight();
    }
  }
  if (!search(data)) {
    cout << "El dato no esta en el arbol ";
  }
}

int BST::whatLevelAmI(int data) {
  NodeT *curr = root;
  int iC=0;

  while ( curr != NULL ) {
    if (curr->getData() == data) {
      return iC;
    }

    if (curr->getData() > data) {
      curr = curr->getLeft();
      iC++;
    }
    else {
      curr = curr->getRight();
      iC++;
    }
  }
  return -1;
}

void BST::mirror() {
  voltear(root);  
}

void BST::voltear(NodeT *r) {  
  if(r!=NULL) {
    NodeT *aux=r->getLeft();
    r->setLeft(r->getRight());
    r->setRight(aux);
    voltear(r->getLeft());
    voltear(r->getRight());
  }
}

int BST::nearestRelative(int uno, int dos) {
  NodeT *curr1 = root;
  NodeT *curr2 = root;
  queue<int> q;
  int NR;
  bool b1=false, b2=false;

  while (!b1) {
    if(curr1->getData()==uno) {
      b1=true;
    }
    q.push(curr1->getData());
    curr1 = (curr1->getData() > uno ? curr1->getLeft() : curr1->getRight());
  }
  while (!b2) {
    if(curr2->getData() == dos) {
      b2=true;
    }
    if(curr2->getData() == q.front()) {
      NR=q.front();
      q.pop();
    }
    curr2 = (curr2->getData() > dos ? curr2->getLeft() : curr2->getRight());
  }
  return NR;
}
/*
bool BST::operator==(const BST &otra) {
  NodeT *curr1 = this->root;
  NodeT *curr2 = otra.root;

  if (curr1 == NULL && curr2 == NULL) {
    return true;
  }
  else if (curr1 == NULL || curr2 == NULL) {
    return false;
  }
  else{
    return checa(curr1, curr2);
  }
}

bool BST::checa(NodeT *c1, NodeT *c2) {
  if (c1 == NULL && c2 == NULL) {
    return true;
  }
  else if (c1 == NULL || c2 == NULL) {
    return false;
  }
  else if (c1 != NULL || c2 != NULL) {
    if (c1->getData() == c2->getData()) {
      return (checa(c1->getLeft(), c2->getLeft()) && checa(c1->getRight(), c2->getRight()));
    }
    else {
      return false;
    }
  }  
}
*/
bool BST::operator == (const BST &otro) {
  return checkPreorder(this->root, otro.root);
}

bool BST::checkPreorder(NodeT *uno, NodeT *dos) {
  if (uno==NULL && dos==NULL) {
    return true;
  }
  if ((uno==NULL && dos!=NULL) || (uno!=NULL && dos==NULL)) {
    return false;
  }
  if (uno->getData() != dos->getData()) {
    return false;
  }
  return checkPreorder(uno->getLeft(), dos->getLeft()) && checkPreorder(uno->getRight(), dos->getRight());
}

int BST::maxWidth() {
  NodeT *curr = root;
  int MW = 0;
  queue<NodeT *> q;

  if (curr == NULL) {
    return MW;
  }

  q.push(curr);
  while ( !q.empty() ) {
    int size = q.size();
    MW = max(size, MW);

    while (size!=0) {
      if (q.front()->getLeft() != NULL) {
        q.push(q.front()->getLeft());
      }
      if (q.front()->getRight() != NULL) {
        q.push(q.front()->getRight());
      }
      size--;
      q.pop();
    }
  }
  return MW;
}
