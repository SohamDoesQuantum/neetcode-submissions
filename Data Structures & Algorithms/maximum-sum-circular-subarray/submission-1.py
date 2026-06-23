class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        res = nums[0]
        maxEnding = nums[0]
        total = nums[0]
        for i in range(1,n):
            maxEnding = max(maxEnding + nums[i],nums[i])
            res = max(res,maxEnding)
            total += nums[i]
        minEnding = nums[0]
        min_so_far= nums[0]
        for i in range(1,n):
            minEnding = min(minEnding+nums[i],nums[i])
            min_so_far = min(min_so_far,minEnding)
        if(total==min_so_far):
            return res
        res = max(res,total-min_so_far)
        return res