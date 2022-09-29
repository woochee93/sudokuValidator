#pragma once
#include <iostream>
class Sudoku
{
   int gameBoard[9][9]{};
   const int boardSize = 9;

public:
   Sudoku(int board[9][9]);
   int *getColumnByIndex(int columnIndex);
   bool isAnyElementRepeatable(int arrToCheck[9]);
   bool areAllValidRows();
   bool areAllValidColumns();
   bool isValidSquare(int x, int y);
   bool areAllValidSquares();
};