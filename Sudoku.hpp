#pragma once

class Sudoku
{
   int gameBoard[9][9];

public:
   int *getColumnByIndex(int columnIndex, int arr[9][9]);
   bool isAnyElementRepeatable(int arrToCheck[9]);
   bool areAllValidRows(int arr[9][9]);
   bool areAllValidColumns(int arr[9][9]);
   bool isValidSquare(int arr[9][9], int x, int y);
   bool areAllValidSquares(int arr[9][9]);
};