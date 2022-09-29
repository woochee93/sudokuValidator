#include "Sudoku.hpp"

Sudoku::Sudoku(int board[9][9])
{
   for (int i{0}; i < boardSize; i++)
   {
      for (int j{0}; j < boardSize; j++)
      {
         gameBoard[i][j] = board[i][j];
      }
   }
}

bool Sudoku::isAnyElementRepeatable(int arrToCheck[9])
{
   for (int i{0}; i < boardSize; i++)
   {
      for (int j{i + 1}; j < boardSize; j++)
      {
         if (arrToCheck[i] == arrToCheck[j])
            return false;
      }
   }
   return true;
}

bool Sudoku::areAllValidRows()
{
   for (int i = 0; i < boardSize; i++)
   {
      if (!isAnyElementRepeatable(gameBoard[i]))
         return false;
   }
   return true;
};
int *Sudoku::getColumnByIndex(int columnIndex)
{
   int *column = new int[boardSize];
   for (int rowIndex{0}; rowIndex < boardSize; rowIndex++)
   {
      column[rowIndex] = gameBoard[rowIndex][columnIndex];
   }
   return column;
};
bool Sudoku::areAllValidColumns()
{
   for (int columnIndex{0}; columnIndex < boardSize; columnIndex++)
   {
      int *columnToCheck = getColumnByIndex(columnIndex);
      bool isNotValid = !isAnyElementRepeatable(columnToCheck);
      delete[] columnToCheck;
      if (isNotValid)
         return false;
   }
   return true;
}

bool Sudoku::isValidSquare(int x, int y)
{
   int arrToCheck[boardSize];
   int index{0};
   const int indexOfRow{x};
   const int indexOfColumn{y};
   for (int rowIndex{x}; rowIndex < (indexOfRow + 3); rowIndex++)
   {
      for (int columnIndex{y}; columnIndex < (indexOfColumn + 3); columnIndex++)
      {
         arrToCheck[index] = gameBoard[rowIndex][columnIndex];
         index++;
      }
   }
   return isAnyElementRepeatable(arrToCheck);
}

bool Sudoku::areAllValidSquares()
{
   for (int i = 0; i < boardSize; i += 3)
   {
      for (int j = 0; j < boardSize; j += 3)
      {
         if (!isValidSquare( i, j))
         {
            return false;
         };
      }
   }
   return true;
}