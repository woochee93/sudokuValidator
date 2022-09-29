#include "Sudoku.hpp"

Sudoku::Sudoku(int board[9][9])
{
   for (int i{0}; i < size; i++)
   {
      for (int j{0}; j < size; j++)
      {
         gameBoard[i][j] = board[i][j];
      }
   }
}

bool Sudoku::isAnyElementRepeatable(int arrToCheck[9])
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

bool Sudoku::areAllValidRows()
{
   for (int i = 0; i < 9; i++)
   {
      if (!isAnyElementRepeatable(gameBoard[i]))
      {
         return false;
      };
   }
   return true;
};
int *Sudoku::getColumnByIndex(int columnIndex)
{
   int *column = new int[9];
   for (int rowIndex{0}; rowIndex < 9; rowIndex++)
   {
      column[rowIndex] = gameBoard[rowIndex][columnIndex];
   }
   return column;
};
bool Sudoku::areAllValidColumns(int arr[9][9])
{
   for (int columnIndex{0}; columnIndex < 9; columnIndex++)
   {
      int *columnToCheck = getColumnByIndex(columnIndex);
      bool isNotValid = !isAnyElementRepeatable(columnToCheck);
      delete[] columnToCheck;
      if (isNotValid)
         return false;
   }
   return true;
}

bool Sudoku::isValidSquare(int arr[9][9], int x, int y)
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
   return isAnyElementRepeatable(arrToCheck);
}

bool Sudoku::areAllValidSquares(int arr[9][9])
{
   for (int i = 0; i < 9; i += 3)
   {
      for (int j = 0; j < 9; j += 3)
      {
         if (!isValidSquare(arr, i, j))
         {
            return false;
         };
      }
   }
   return true;
}