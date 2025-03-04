class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), element = 0, count = 0;
        for(int i=0; i<n; i++){
            if(count == 0){
                element = nums[i];
            }
            if(nums[i] == element) count++;
            else count--;
        }
        return element;
    }
};