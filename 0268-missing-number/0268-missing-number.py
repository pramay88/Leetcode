class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        sum = n*(n+1)/2
        for n in nums:
            sum -= n
        return int(sum)