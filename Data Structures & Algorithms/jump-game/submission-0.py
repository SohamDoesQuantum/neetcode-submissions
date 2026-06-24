class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        farthest = 0
        for i in range(n-1):
            curr = i+nums[i]
            if(i>farthest):
                return False
            if(farthest < curr):
                farthest = curr
            
        if(farthest>=n-1):
            return True
        return False