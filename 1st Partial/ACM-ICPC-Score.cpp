#include <iostream>
#include <string>
using namespace std;

struct Equipo
{
  string sNombreEquipo;
  int arrW[10] = {0,0,0,0,0,0,0,0,0,0};
  int iAcc = 0;
  int iTiempo = 0;
}; 

void QuickSort(Equipo* arr, int izq, int der)
{
  int i=izq, j=der;
  Equipo pivote = arr[(izq+der)/2];
  Equipo temp;

  while(i <= j)
  {
    while (arr[i].iAcc > pivote.iAcc) i++;
    while (arr[j].iAcc < pivote.iAcc) j--;
    if (i<=j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++; j--;
    }
  }

  if(izq < j)
  {
    QuickSort(arr, izq, j);
  }

  if(i < der)
  {
    QuickSort(arr, i, der);
  }
}

void OrderTime(Equipo* arr, int fin)
{
  Equipo menor, temp;
  int pos;
  
  for (int i=0; i<fin; i++)
  {
    menor = arr[i];

    for (int j=i; (j<fin)&&(arr[j].iAcc == arr[i].iAcc); j++)
    {
      if (arr[j].iTiempo < menor.iTiempo)
      {
        menor = arr[j];
        pos = j;
      }
    }

    if (arr[i].iTiempo != menor.iTiempo){
    temp = arr[i];
    arr[i] = menor;
    arr[pos] = temp;
    }
  }
}

int main() {
  int iT=0, iP=0, iSS=0, iTime, iTTemp; 
  string sNombre, sNTemp;
  char cNameProblem, cJudge, cPTemp, cStatus;
  Equipo equipo[20];

  //cout << "\nGive me the number of teams: ";
  cin >> iT;
  if (iT < 1 || iT > 20)
  {
    return 0;
  }

  //cout << "Give me the number of problems: ";
  cin >> iP;
  if (iP < 1 || iP > 10)
  {
    return 0;
  }

  for (int i=0; i<iT; i++)
  {
    cin >> equipo[i].sNombreEquipo;
  }
  
  //cout << "Give the number of solutions sent: ";
  cin >> iSS;
  if (iSS <=0 || iSS >= 1001)
  {
    return 0;
  }

  for (int i=0; i<iSS; i++)
  {
    cin >> sNTemp >> cPTemp >> iTTemp >> cStatus;
    int aux;

    for (int j=0; j<20; j++)
    {
      if (equipo[j].sNombreEquipo == sNTemp)
      {
        aux=j;
      }
    }
  
    if (cStatus == 'A')
    {
      equipo[aux].iTiempo += iTTemp+(20*equipo[aux].arrW[cPTemp-'A']);
      equipo[aux].iAcc += 1;
    }

    else
    {
      equipo[aux].arrW[cPTemp-'A']++;
    }
  }

  QuickSort(equipo, 0, iT-1); 
  OrderTime(equipo, iT);

  for (int i=0; i<iT; i++)
  {
    cout << i+1 << " - " << equipo[i].sNombreEquipo << " " << equipo[i].iAcc << " ";
    if (equipo[i].iTiempo==0)
    {
      cout << "-" << endl;
    }
    else
    {
      cout << equipo[i].iTiempo << endl;
    }
  } 
}
