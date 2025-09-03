class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = longest = zeros = 0
        for right in range(len(nums)):
            if(nums[right] == 0): zeros += 1
            if zeros > k:
                if(nums[left] == 0): zeros -= 1
                left += 1
            longest = max(longest, right - left + 1)
        return longest