#include <iostream>
using namespace std;

void getValues(int iMat[][9])
{
  //cout << "Give me the numbers: " << endl;
  for (int rows=0; rows <9; rows++)
  {
    for (int cols=0; cols <9; cols++)
    {
      cin >> iMat[rows][cols];
    }
  }
}

/*void display(int iMat[][9])
{
  cout << "\n\nLa matriz se ve así:\n"<< endl;
  for (int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++)
    {
      cout << iMat[i][j];
      if (j<8)
      {
        cout << " ";
      }
    }
    cout << "\n";
  }
  cout << "\n\n";
}*/

void checkSudoku(int iMat[][9], bool &verif)
{
  int x; int lim; int limI; int limJ;
  
  //Checando fila por fila (ROWS)
  for(int row=0; row<9; row++)
  {
    for (int col=0; col<9; col++)
    {
      x=iMat[row][col];
      lim = col;

      for (int j=0; j<9; j++)
      {
        if (j==lim)
        {
          j++;
        }

        if (iMat[row][j]==x)
        {
          verif=false;
        }
      }
    }
  }

  //Checando col por col  (COLS)
  for(int row=0; row<9; row++)
  {
    for (int col=0; col<9; col++)
    {
      x=iMat[row][col];
      lim = row;

      for (int i=0; i<9; i++)
      {
        if (i==lim)
        {
          i++;
        }

        if (iMat[i][col]==x)
        {
          verif=false;
        }
      }
    }
  }

  //Checando las matrices de 3x3
  //Dos for loops para pasar por las 9 mini-matrices
  for (int row=0; row<9; row+=3)
  {
    for (int col=0; col<9; col+=3)
    {
      //Dos for loops para revisar por adentro cada mini-matriz
      for (int i=0; i<3; i++)
      {
        for (int j=0; j<3; j++)
        {
          x=iMat[i][j];
          limI=i;
          limJ=j;

          if (limI==i && limJ==j)
          {
            j++;
          }

          if (j<3)
          {
            if (iMat[i][j]==x)
            {
              verif=false;
            }
          }
        }
      }
    }
  }

  //Para numero grandes
  for (int i=0; i<9; i++)
  {
    for (int j=0; j<9; j++)
    {
      if (iMat[i][j]<1 || iMat[i][j]>9)
      {
        verif=false;
      }
    }
  }

}

void result(bool verif)
{
  if (verif == true)
  {
    cout << "YES" << endl;
  }
  else if (verif == false)
  {
    cout << "NO" << endl;
  }
}

int main() {
  int iMat[9][9];
  bool verif = true;
  getValues(iMat);
  //display(iMat);
  checkSudoku(iMat, verif);
  result(verif);
}
