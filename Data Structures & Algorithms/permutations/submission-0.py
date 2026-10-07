class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path  = []
        used = [False] * len(nums)

        def backtrack(idx):
            if(len(path) == len(nums)):
                ans.append(path.copy())

            for i in range(0,len(nums)):
                if(used[i] == True):
                    continue
                
                path.append(nums[i])
                used[i] = True
                backtrack(i)
                path.pop()
                used[i] = False
        
        backtrack(0)

        return ans        
        