#pragma once
#include <iostream>
class Sudoku
{
   int gameBoard[9][9];
   const int size = 9;

public:
   Sudoku(int board[9][9]);
   int *getColumnByIndex(int columnIndex);
   bool isAnyElementRepeatable(int arrToCheck[9]);
   bool areAllValidRows(int arr[9][9]);
   bool areAllValidColumns(int arr[9][9]);
   bool isValidSquare(int arr[9][9], int x, int y);
   bool areAllValidSquares(int arr[9][9]);
};