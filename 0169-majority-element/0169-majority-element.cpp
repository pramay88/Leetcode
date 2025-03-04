class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0, count = 0;
        for(int n: nums){
            if(count == 0) element = n;
            count += (n == element)? 1: -1;
        }
        return element;
    }
};