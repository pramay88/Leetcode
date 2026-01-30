class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxx = nums[0], leftProd = 1, rightProd = 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            leftProd *= nums[i];
            rightProd *= nums[n - 1 - i];
            
            maxx = max(maxx, max(leftProd, rightProd));
            
            if(leftProd == 0) leftProd = 1;
            if(rightProd == 0) rightProd = 1;
        }
        return maxx;
    }
};