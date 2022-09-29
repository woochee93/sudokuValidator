#pragma once

class Sudoku
{
   int board[9][9];

public:
   void getColumnByIndex(int columnIndex,int column[9], int arr[9][9]);
   bool checkRepetitions(int arrToCheck[9]);
   bool checkAllRow(int arr[9][9]);
   bool checkAllColumns(int arr[9][9]);
   bool checkSquare(int arr[9][9], int x, int y);
   bool checkAllSquares(int arr[9][9]);
};