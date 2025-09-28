class Solution {
    bool check(int a, int b, int c){
        if(a + b <= c) return false;
        if(b + c <= a) return false;
        if(a + c <= b) return false;
        return true;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 1; i >= 2; i--) {
            if(check(nums[i], nums[i-1], nums[i-2]))
                return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
};