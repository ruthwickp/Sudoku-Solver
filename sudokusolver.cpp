//
//  sudokusolver.cpp
//  
//
//  Created by Ramruthwick Pathireddy on 5/13/14.
//
//
//  This program solves a sudoku puzzle given by the user
//  as a text file and prints it out. Uses the sudokuboard
//  header file to create the board and utilize its functions.
//  The algorithm used for solving the sudoku is a brute-force
//  method with recursion.
//
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sudokuboard.h"

// Function prototypes
bool solve(SudokuBoard board);

int main(int argc, char *argv[])
{
    // Makes sure two arguments are provided
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " filename" << std::endl;
        exit(1);
    }
    
    // Reads file given from command-line argument and stores the
    // integers in the sudoku array
    int sudoku[81];
    std::string numbers = "";
    std::ifstream sudokuFile(argv[1]);
    if (sudokuFile.is_open())
    {
        std::string line;
        while (std::getline(sudokuFile, line))
        {
            numbers.append(line);
        }
        sudokuFile.close();
    }
    for (int i = 0; i < 81; i++)
    {
        sudoku[i] = numbers[i] - '0';
    }

    
    // Creates a SudokuBoard object from our input board
    SudokuBoard board(sudoku);    
    std::cout << "Your board: " << std::endl;
    board.printBoard();
    std::cout << std::endl;
    if (solve(board))
    {
        std::cout << "The board is solved." << std::endl;
    }
    else
    {
        std::cout << "The board has no solution" << std::endl;
    }
    return 0;
}

/*
 * Function that solves the sudoku board by using recursive backtracking.
 * It checks to see if the given board if solvable by solving a
 * simpler board with a given valid value inserted into an empty location.
 * The base case is when the empty locations is zero, indicating that
 * a solution exists. If the base case is reached, we print out the
 * solved board.
 *
 * @param board -- sudoku board going to be solved
 * 
 * @return a boolean value indicating it the board is solvable
 */
bool solve(SudokuBoard board)
{
    std::vector<int *> openLoc = board.emptyLocations();
    
    // Base case
    if (openLoc.size() == 0)
    {
        board.printBoard();
        return true;
    }
    
    // If an open location exists, we fill it in with some valid number
    int *cell = openLoc[0];
    std::vector<int> validNumbers = board.validNums(cell[0], cell[1]);
    for (int j = 0; j < validNumbers.size(); j++)
    {
        // If board is solvable, return 1
        board.insertElem(cell[0], cell[1], validNumbers[j]);
        if (solve(board))
        {
            return 1;
        }
        board.insertElem(cell[0], cell[1], 0);
    }
    
    // If no valid number exists, return 0
    return 0;
    
}