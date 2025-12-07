class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return int((high - low) / 2) if (low % 2 == 0 and high % 2 == 0) else int((high - low) / 2) + 1
