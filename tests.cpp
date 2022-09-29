#include <gtest/gtest.h>
#include "Sudoku.hpp"

class Fixture : public testing::Test
{
protected:
   int solvedBoard[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}};

   int failedBoard[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                           {6, 7, 2, 1, 9, 0, 3, 4, 8},
                           {1, 0, 0, 3, 4, 2, 5, 6, 0},
                           {8, 5, 9, 7, 6, 1, 0, 2, 0},
                           {4, 2, 6, 8, 5, 3, 7, 9, 1},
                           {7, 1, 3, 9, 2, 4, 8, 5, 6},
                           {9, 0, 1, 5, 3, 7, 2, 1, 4},
                           {2, 8, 7, 4, 1, 9, 6, 3, 5},
                           {3, 0, 0, 4, 8, 1, 1, 7, 9}};
   int validRow[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int validRow2[9] = {5, 6, 3, 2, 8, 1, 4, 7, 9};
   int invalidRow[9] = {1, 6, 3, 2, 8, 1, 4, 7, 9};
   Sudoku solvedSudoku{solvedBoard};
   Sudoku failedSudoku{failedBoard};
};



TEST_F(Fixture, bossTest){
   EXPECT_TRUE(solvedSudoku.areAllValidSquares());
   EXPECT_FALSE(failedSudoku.areAllValidSquares());

   EXPECT_TRUE(solvedSudoku.areAllValidColumns());
   EXPECT_FALSE(failedSudoku.areAllValidColumns());

   EXPECT_TRUE(solvedSudoku.areAllValidRows());
   EXPECT_FALSE(failedSudoku.areAllValidRows());

}


TEST_F(Fixture, checkAllSquare){
   EXPECT_TRUE(solvedSudoku.areAllValidSquares());
   EXPECT_FALSE(failedSudoku.areAllValidSquares());
}


TEST_F(Fixture, checkSquare){
   EXPECT_TRUE(solvedSudoku.isValidSquare(0,0));
   EXPECT_FALSE(failedSudoku.isValidSquare(0,0));
}


TEST_F(Fixture, checkAllColumns)
{
   EXPECT_TRUE(solvedSudoku.areAllValidColumns());
   EXPECT_FALSE(failedSudoku.areAllValidColumns());
}

TEST_F(Fixture, checkAllRows)
{
   EXPECT_TRUE(solvedSudoku.areAllValidRows());
   EXPECT_FALSE(failedSudoku.areAllValidRows());
}

TEST_F(Fixture, checkRepetitions)
{
   EXPECT_TRUE(solvedSudoku.isAnyElementRepeatable(validRow));
   EXPECT_TRUE(solvedSudoku.isAnyElementRepeatable(validRow2));
   EXPECT_FALSE(solvedSudoku.isAnyElementRepeatable(invalidRow));
}
