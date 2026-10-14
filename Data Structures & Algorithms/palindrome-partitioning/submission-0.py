class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        path = []

        def backtrack(idx):
            if (idx == len(s)):
                ans.append(path.copy())
                return

            for i in range (idx,len(s)):
                substr = s[idx:i+1]

                if ( substr == substr[::-1]):
                    path.append(substr)
                    backtrack(i+1)
                    path.pop()

        
        backtrack(0)
        return ans
