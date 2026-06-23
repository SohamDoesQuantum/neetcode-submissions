class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res1 = 0
        for n in nums:
            res1 = res1 ^ n
        res2 = 0
        for n in range(len(nums)+1):
            res2 = res2 ^ n
        return res1^res2