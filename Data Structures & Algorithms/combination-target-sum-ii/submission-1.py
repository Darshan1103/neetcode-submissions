class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        path = []

        def backtrack(idx, sum):
            if(sum == target):
                ans.append(path.copy())
                return

            for i in range(idx, len(candidates)):
                if(i > idx and candidates[i] == candidates[i-1]):
                    continue
                if(sum + candidates[i] > target):
                    continue
                path.append(candidates[i])
                backtrack(i + 1, sum + candidates[i])
                path.pop()
            
        backtrack(0,0)
        return ans