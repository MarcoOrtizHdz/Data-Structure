#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int myStoi(string s)
{
  int salida = 0;
  for (int i=0; i<s.length(); i++)
  {
    salida=(salida*10)+(s[i]-'0');
  }
  return salida;
}

int Operacion(int x, int y, string s)
{
  if (s=="+") {
    return x + y;
  }

  else if (s =="-") {
    return x - y;
  }

  else if (s=="*") {
    return x * y;
  }

  else {
    return -1;
  }
}

void stackLogica (stack<int> &s, int a, int b, string d, int &result)
{
  //Sacando el segundo operando
  a=s.top();
  s.pop();
  //Sacando el primer operando
  b=s.top();
  s.pop();
  //Sacando el resultado y poniéndolo en el stack
  result= Operacion(b, a, d);
  s.push(result);
}

void queueLogica (queue<int> &q, int a, int b, string d, int &res)
{
  //Sacando el segundo operando
  a=q.front();
  q.pop();
  //Sacando el primer operando
  b=q.front();
  q.pop();
  //Sacando el resultado y poniéndolo en el queue
  res=Operacion(b, a, d);
  q.push(res);
}

void priorityQueueLogica(priority_queue<int, vector<int>, greater<int> > &pq, int a, int b, string d, int &res)
{
  //Sacando el segundo operando
  a=pq.top();
  pq.pop();
  //Sacando el tercer operando
  b=pq.top();
  pq.pop();
  //Sacando el resultado y poniéndolo en el priority queue
  res = Operacion (b, a, d);
  pq.push(res);
}

void stackDel(stack<int> &s)
{
  while (!s.empty()){
    s.pop();
  }
}

void queueDel(queue<int> &q)
{
  while (!q.empty()) {
    q.pop();
  }
}

void priorityQueueDel(priority_queue<int, vector<int>, greater<int> > &pq)
{
  while (!pq.empty()) {
    pq.pop();
  }
}

int main() {
  string d, data; 
  int a, b, resStack, resQueue, resPriorityQueue;
  stack<int> s;
  queue<int> q;
  priority_queue<int, vector<int>, greater<int> > pq;

  getline(cin, data);
  while (data != "#") {
    stringstream ss;
    ss << data;

    while (ss >> d) { 
      if ( d=="+" || d=="-" || d=="*"){
        //Logica de cada estructura
        stackLogica(s, a, b, d, resStack);
        queueLogica(q, a, b, d, resQueue);
        priorityQueueLogica(pq, a, b, d, resPriorityQueue);
      }

      else {
        //Meter valores a cada estructura
        s.push(myStoi(d));
        q.push(myStoi(d));
        pq.push(myStoi(d));
      }
    }
  
    //cout << "Termine la linea" << endl;
    cout << resStack << " " << resQueue << " " << resPriorityQueue << endl;
    getline(cin, data);
    stackDel(s);
    queueDel(q);
    priorityQueueDel(pq);
  }
  return 0;
} 
