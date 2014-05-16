//
//  sudokuboard.cpp
//  
//
//  Created by Ramruthwick Pathireddy on 5/13/14.
//
//
//  Implementation file for the header file sudokuboard.h.
//  It contains a default constructor as well as another
//  constructor to initialize the sudoku board to a particular
//  setting. Basic functions implemented include printing the
//  board, getting open locations on the board, and finding
//  possible values at a given cell location using a simple
//  row, column, and box checking strategy.
//
//

#include <iostream>
#include "sudokuboard.h"

/* 
 * Constructor initializes the sudoku board to have values of 
 * zero everywhere.
 */
SudokuBoard::SudokuBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = 0;
        }
    }
}

/*
 * Constructor that initalizes the sudoku board to contain
 * the elements of the input array. The input array must
 * contain 81 elements.
 */
SudokuBoard::SudokuBoard(int board[])
{
    for (int i = 0; i < 81; i++)
    {
        int row = i / 9;
        int col = i % 9;
        this->board[row][col] = board[i];
    }
}

/*
 * Function scans through the sudoku board and finds the 
 * locations which are empty (containing zero value), and
 * returns them.
 *
 * @return a vector of locations with locations represented
 * by a size 2 array as [row, col].
 */
std::vector<int *> SudokuBoard::emptyLocations()
{
    std::vector<int *> locations;
    for (int i  = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                int *loc = new int[2];
                loc[0] = i;
                loc[1] = j;
                locations.push_back(loc);
            }
        }
    }
    return locations;
}

/*
 * Function computes valid numbers possible at a given row
 * and column location in the sudoku board. Then returns the
 * values.
 *
 * @param row -- integer indicating row location
 * @param col -- integer indication column location
 *
 * @return a vector of valid numbers at location (row, col)
 */
std::vector<int> SudokuBoard::validNums(int row, int col)
{
    std::set<int> invalidNums;
    
    // Checks for row and column numbers
    for (int i = 0; i < 9; i++)
    {
        invalidNums.insert(board[row][i]);
    }
    for (int i = 0; i < 9; i++)
    {
        invalidNums.insert(board[i][col]);
    }
    
    // Checks for box numbers
    int topLeftRow = (row / 3) * 3;
    int topLeftCol = (col / 3) * 3;
    for (int i = topLeftRow; i < topLeftRow + 3; i++)
    {
        for (int j = topLeftCol; j < topLeftCol + 3; j++)
        {
            invalidNums.insert(board[i][j]);
        }
    }
    
    // Finds the valid numbers and returns it
    std::vector<int> validNumbers;
    for (int i = 1; i < 10; i++)
    {
        if (invalidNums.find(i) == invalidNums.end())
        {
            validNumbers.push_back(i);
        }
    }
    return validNumbers;
}

/*
 * Function inserts the value at the given row and column
 * index of the board. No return value.
 *
 * @param row -- row of board
 * @param col -- column of board
 * @param value -- value to be inserted
 */
void SudokuBoard::insertElem(int row, int col, int value)
{
    board[row][col] = value;
}

/*
 * Function prints the sudoku board out onto the terminal. 
 * Does not return anything.
 */
void SudokuBoard::printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}