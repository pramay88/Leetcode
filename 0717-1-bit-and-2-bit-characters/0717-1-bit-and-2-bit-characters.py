class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        x = 0
        while x < len(bits) - 1: x += bits[x] + 1
        return x == len(bits) - 1