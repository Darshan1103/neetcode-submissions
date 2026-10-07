class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        path = []

        def backtrack(idx):
            if(path not in ans):
                ans.append(path.copy())

            for i in range(idx, len(nums)):
                if i > idx and nums[i] == nums[i-1]:
                    continue
                path.append(nums[i])
                backtrack(i+1)
                path.pop()

        backtrack(0)
        return ans

