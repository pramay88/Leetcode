class Solution:
    def bestClosingTime(self, customers: str) -> int:
        penalty = 0
        for c in customers:
            if c == 'Y': penalty += 1
        minPenalty, bestHour = penalty, 0

        for i in range(len(customers)):
            if customers[i] == 'Y': penalty -= 1
            else: penalty += 1
            if penalty < minPenalty:
                minPenalty = penalty
                bestHour = i + 1
        return bestHour