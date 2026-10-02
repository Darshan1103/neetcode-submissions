class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []

        def backtrack(idx):
            ans.append(path.copy())

            for i in range(idx, len(nums)):
                path.append(nums[i])

                backtrack(i+1)

                path.pop()
        
        backtrack(0)

        return ans
        