class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        row , col = len(board), len(board[0])
        visited = [[False for _ in range(col)] for _ in range(row)]
        def dfs(idx, r, c):
            if idx == len(word): return True
            if r>=row or c>=col or r<0 or c<0 or visited[r][c] or word[idx]!=board[r][c]: return False
            visited[r][c] = True
            possible = (
                dfs(idx+1, r+1 , c) or 
                dfs(idx+1, r-1, c) or 
                dfs(idx+1, r, c-1) or dfs(idx+1, r, c+1)
                )
            visited[r][c] = False
            return possible
        for r in range(row):
            for c in range(col):
                if word[0] == board[r][c] and dfs(0, r, c):
                    return True
        return False