#!/usr/bin/python3

import sys
if len(sys.argv) is not 2:
    print('Usage: nqueens N')
    exit(1)
n = sys.argv[1]
try:
    n = int(n)

except:
    print('N must be a number')
    exit(1)

if n < 4:
    print('N must be at least 4')
    exit(1)

k = 1


def printSolution(board):
    queens = []
    global k
    k = k + 1
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                queens.append([i, j])
    print(queens)


def isSafe(board, row, col):
    for i in range(col):
        if (board[row][i]):
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while j >= 0 and i < n:
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1
    return True


def solveNQUtil(board, col):
    ''' base case: If all queens are placed
    then return true '''
    if (col == n):
        printSolution(board)
        return True
    res = False
    for i in range(n):
        if (isSafe(board, i, col)):
            board[i][col] = 1
            res = solveNQUtil(board, col + 1) or res
            board[i][col] = 0
    return res


def solveNQ():
    board = [[0 for j in range(n)] for i in range(n)]
    if (solveNQUtil(board, 0) is False):
        pass
        return
    return

solveNQ()
