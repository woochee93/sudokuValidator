#include "Sudoku.hpp"

bool Sudoku::checkRepetitions(int arrToCheck[9])
{
   for (int i{0}; i < 9; i++)
   {
      for (int j{i + 1}; j < 9; j++)
      {
         if (arrToCheck[i] == arrToCheck[j])
            return false;
      }
   }
   return true;
}

bool Sudoku::checkAllRow(int arr[9][9])
{
   for (int i = 0; i < 9; i++)
   {
      if (!checkRepetitions(arr[i]))
      {
         return false;
      };
   }
   return true;
};

bool Sudoku::checkAllColumns(int arr[9][9])
{
   for (int columnIndex{0}; columnIndex < 9; columnIndex++)
   {
      int column[9];
      for (int rowIndex{0}; rowIndex < 9; rowIndex++)
      {
         column[rowIndex] = arr[rowIndex][columnIndex];
      }
      if (!checkRepetitions(column))
      {
         return false;
      }
   }
   return true;
}

bool Sudoku::checkSquare(int arr[9][9], int x, int y)
{
   int arrToCheck[9];
   int index{0};
   const int indexOfRow{x};
   const int indexOfColumn{y};
   for (int rowIndex{x}; rowIndex < (indexOfRow + 3); rowIndex++)
   {
      for (int columnIndex{y}; columnIndex < (indexOfColumn + 3); columnIndex++)
      {
         arrToCheck[index] = arr[rowIndex][columnIndex];
         index++;
      }
   }
   return checkRepetitions(arrToCheck);
}

bool Sudoku::checkAllSquares(int arr[9][9]){
    for (int i = 0; i < 9; i+=3)
    {
       for (int j = 0; j < 9; j+=3)
       {
        if(!checkSquare(arr,i,j)){
            return false;
        };
       }
       
    }
    return true;
}