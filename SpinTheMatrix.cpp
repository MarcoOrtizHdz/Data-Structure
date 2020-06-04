#include <iostream>
using namespace std;

void getValues(int iMat[][4], int &spin)
{
  do
  {
    //cout << "Give me the number of spins: ";
    cin >> spin;
    /*if (spin<=-10000 || spin>=10000)
    {
      cout << "Give me another number\n";
    }*/
  } while (spin<=-10000 || spin>=10000);
  
  //storing the values in the matrix
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<4; j++)
    {
      cin >> iMat[i][j];
    }
  }
}

void spinTheMatrix(int iMat[][4], int spin, int &numSpin)
{ 
  int iNew[4][4];
  numSpin = spin%4;
  //in case that the user enters a negative number
  if (numSpin<0)
  {
    numSpin+=4;
  }  

  for (int i=0; i<numSpin; i++)
  {
    for (int j=0, o=3; j<4; j++, o--)
    {
      for (int k=0, n=0; k<4; k++, n++)
      {
        iNew[n][o] = iMat[j][k];
      }
    }

    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)
      {
        iMat[i][j] = iNew[i][j];
      }
    }
  }

  for (int i=0; i<4; i++)
  {
    for (int j=0; j<4; j++)
    {
      cout << iMat[i][j];
      if (j<3)
      {
        cout << " ";
      }
    }
    cout << "\n";
  }

}

int main() {
  int spin = -11000; int iMat[4][4]; int numSpin; 
  getValues(iMat, spin);
  spinTheMatrix(iMat, spin, numSpin);
}
