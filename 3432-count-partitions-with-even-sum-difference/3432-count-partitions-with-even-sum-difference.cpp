class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), total = 0;
        for(int i: nums) total += i;      
        
        if(total % 2 != 0) return 0;
        
        return n - 1;
    }
};