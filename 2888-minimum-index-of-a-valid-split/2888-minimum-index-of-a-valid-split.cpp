class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        //Finding the dominant element using Boyer-Moore Majority Vote Algorithm
        int element = -1, count = 0;
        for(int num: nums){
            if(count == 0) element = num;
            count += (num == element)? 1: -1;
        }

        int elementCount = 0;
        for(int num: nums){
            if(num == element) elementCount++;
        }

        int n = nums.size();
        if (elementCount*2 <= n) return -1;
        int leftCount = 0;

        for(int i=0; i<n-1; i++){
            if(nums[i] == element) leftCount++;
            if((2*leftCount > i+1) && 2*(elementCount - leftCount) > (n-i-1))
                return i;
        }
        return -1;
    }
};