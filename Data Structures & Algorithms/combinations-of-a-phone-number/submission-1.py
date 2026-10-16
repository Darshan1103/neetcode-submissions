class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        alpha = {"1":"","2":"abc", "3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
        ans = []
        s = ""
        if digits == "":
            return ans 

        def backtrack(i,s):
            if len(digits) == i:
                ans.append(s)
                return

            letters = alpha[digits[i]]

            for char in letters:
                s += char
                backtrack(i+1,s)
                s = s[0:len(s)-1]

        backtrack(0,s)
        return ans

                

