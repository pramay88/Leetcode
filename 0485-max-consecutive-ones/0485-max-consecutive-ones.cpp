class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for(int i: nums){
            count += i;
            maxCount = max(maxCount, count);
            if(i == 0) count = 0;
        }
        return maxCount;
    }
};