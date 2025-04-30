class Solution {
    int countDigits(int num){
        if(num == 0) return 1;
        return floor(log10(num) + 1);
    }
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num: nums){
            if(!(countDigits(num) & 1)) count++;
        }
        return count;
    }
};