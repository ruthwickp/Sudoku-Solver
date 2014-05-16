#
# Makefile for the sudoku program
#

CC = g++
OBJS = sudokusolver.o sudokuboard.o

all: $(OBJS)
	$(CC) $(OBJS) -o sudokusolver

sudokusolver.o: sudokusolver.cpp sudokuboard.h
	$(CC) -Wall -c sudokusolver.cpp sudokusolver.cpp

sudokuboard.o: sudokuboard.cpp sudokuboard.h
	$(CC) -Wall -c sudokuboard.cpp

clean:
	rm -f sudokusolver $(OBJS)