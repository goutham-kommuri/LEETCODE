class Solution(object):
    def canJump(self, nums):
        mx, n = 0, len(nums)
        for i in range(n):
            mx = max(mx, nums[i]+i)
            if not nums[i]:
                if i+1 == n: break
                if(mx == i): return False
        return True