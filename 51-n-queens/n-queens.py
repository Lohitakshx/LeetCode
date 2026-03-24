class Solution:
    def solve(self, ans, board, n, col, upperD, leftCol, lowerD):
        if col == n : 
            ans.append(["".join(row) for row in board])
            return 
        for row in range(n):
            if row not in leftCol and row+col not in upperD and row-col not in lowerD:
                leftCol.add(row)
                upperD.add(row+col)
                lowerD.add(row-col)
                board[row][col] = 'Q'
                self.solve(ans, board, n, col+1, upperD, leftCol, lowerD)
                leftCol.remove(row)
                upperD.remove(row+col)
                lowerD.remove(row-col)
                board[row][col] = '.'

    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        board = [['.'] * n for _ in range(n)]
        self.solve(ans, board, n, 0, set(), set(), set())
        return ans