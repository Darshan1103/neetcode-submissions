class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])

        def backtrack(i , j , idx):
            if(idx == len(word)):
                return True

            if ( i < 0  or j < 0 or  i >= m or  j >= n):
                return False
            
            if(board[i][j] != word[idx]):
                return False
            
            temp = board[i][j]
            board[i][j] = "#"

            found = (
                backtrack(i+1, j, idx+1) or
                backtrack(i-1, j, idx+1) or
                backtrack(i, j+1, idx+1) or
                backtrack(i, j-1, idx+1)
            )

            board[i][j] = temp
            return found            

        for i in range(m):
            for j in range(n):
                if backtrack(i, j , 0):
                    return True
        
        return False

            

