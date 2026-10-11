class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        path = ""

        def backtrack(path,l,r):
            if (l == n and r == n):
                ans.append(path)
            
            
            if(l < n):
                path += "("
                backtrack(path,l+1,r)
                path = path[:-1]
            if(r < l):
                path += ")"
                backtrack(path,l,r+1)
                path = path[:-1]

        backtrack(path,0,0)
        return ans