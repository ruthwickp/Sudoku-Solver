//
//  sudokuboard.h
//  
//
//  Created by Ramruthwick Pathireddy on 5/13/14.
//
//
//  Header file for the sudoku board class.
//
//

#ifndef _sudokuboard_h
#define _sudokuboard_h

#include <vector>
#include <set>

class SudokuBoard
{
private:
    int board[9][9];
    
public:
    SudokuBoard();
    SudokuBoard(int board[]);
    std::vector<int *> emptyLocations();
    std::vector<int> validNums(int row, int col);
    void insertElem(int row, int col, int value);
    void printBoard();
    
    
};


#endif
