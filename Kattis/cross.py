"""
Problem: cross
Link: https://open.kattis.com/problems/cross
Source: Croatian Open Competition in Informatics 2008/2009, contest #3
"""
from collections import defaultdict

def runBoard(board):
    """
    Solve the board by pruning
    """
    possibilities = [[set() for c in range(9)] for r in range(9)]
    for r in range(9):
        for c in range(9):
            for n in range(1, 10):
                possibilities[r][c].add(n)

    def pruneAll(row, col):
        possibilities[row][col] = set()

    def pruneRow(row, num):
        """
        Prune row
        """
        for i in range(9):
            if num in possibilities[row][i]:
                possibilities[row][i].remove(num)

    def pruneCol(col, num):
        """
        Prune column
        """
        for i in range(9):
            if num in possibilities[i][col]:
                possibilities[i][col].remove(num)

    def pruneBlock(block, num):
        """
        Prune 3x3 block
        """
        row = block // 3 * 3
        col = (block % 3) * 3
        for i in range(3):
            for j in range(3):
                if num in possibilities[row+i][col+j]:
                    possibilities[row+i][col+j].remove(num)

    def getBlock(row, col):
        return (row // 3)*3 + (col // 3)

    for r in range(9):
        for c in range(9):
            if(board[r][c] != '.'):
                block = getBlock(r,c)
                num = int(board[r][c])
                pruneAll(r, c)
                pruneBlock(block, num)
                pruneRow(r, num)
                pruneCol(c, num)

    # Iteratively prune the board
    while True:
        possible = False
        for num in range(1,10):
            for block in range(9):
                counter = 0
                position = None
                for r in range(block//3*3, block//3*3+3):
                    for c in range(block%3*3, block%3*3+3):
                        if board[r][c] != '.': continue
                        if num in possibilities[r][c]:
                            counter += 1
                            position = (r,c)

                if counter == 1:
                    possible = True
                    board[position[0]][position[1]] = str(num)
                    pruneBlock(block, num)
                    pruneRow(position[0], num)
                    pruneCol(position[1], num)

        if not possible:
            break

    def checkBoard(board):
        def checkRow(row, num):
            counter = 0
            for c in range(9):
                if(board[row][c] != '.'): counter += (int(board[row][c]) == num)
            return counter <= 1

        def checkCol(col, num):
            counter = 0
            for r in range(9):
                if(board[r][col] != '.'): counter += (int(board[r][col]) == num)
            return counter <= 1

        def checkBlock(block, num):
            counter = 0
            for r in range(block//3*3, block//3*3+3):
                for c in range(block%3*3, block%3*3+3):
                    if board[r][c] != '.':    counter += (int(board[r][c]) == num)

            if counter > 1: return False
            elif counter == 1: return True
            else:
                for r in range(block//3*3, block//3*3+3):
                    for c in range(block%3*3, block%3*3+3):
                        if num in possibilities[r][c]:
                            return True
                return False


        for num in range(1,10):
            for i in range(9):
                if not checkRow(i,num): return False
                if not checkCol(i,num): return False
                if not checkBlock(i, num): return False

        return True

    if not checkBoard(board):
        return "ERROR"
    else:
        return board

board = []
for i in range(9):
    string = list(input())
    board.append(string)

solvedBoard = runBoard(board)
if type(solvedBoard) == str:
    print("ERROR")
else:
    for r in range(9):
        for c in range(9):
            print(solvedBoard[r][c], end="")
        print("")
