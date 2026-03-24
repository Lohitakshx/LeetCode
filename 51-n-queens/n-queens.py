class Solution:
    def isSafe(self, board, row, col, n) -> bool:
        temp_row = row
        temp_col = col
        while row >= 0 and col >= 0:
            if board[row][col] == 'Q':
                return False
            col-=1
            row-=1
        row, col = temp_row, temp_col
        while col >= 0:
            if board[row][col] == 'Q':
                return False
            col-=1
        row, col = temp_row, temp_col
        while row < n and col >= 0:
            if board[row][col] == 'Q':
                return False
            col-=1
            row+=1
        return True

    def solve(self, ans, board, n, col):
        if col == n : 
            ans.append(["".join(row) for row in board])
            return
        for row in range(n):
            if self.isSafe(board, row, col, n):
                board[row][col] = 'Q'
                self.solve(ans, board, n, col+1)
                board[row][col] = '.'

    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        board = [['.'] * n for _ in range(n)]
        self.solve(ans, board, n, 0)
        return ans