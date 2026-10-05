class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []

        def backtrack(idx, sum):
            if( sum == target ):
                ans.append(path.copy())
                return
            
            for i in range(idx,len(nums)):
                if nums[i] + sum > target:
                    continue
                path.append(nums[i])
                backtrack(i,sum + nums[i])
                path.pop()
        
        backtrack(0,0)
        return ans