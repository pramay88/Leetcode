class Solution {
    int digitSum(int num){
        int sum = 0;
        while(num != 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> hash;
        int maxSum = -1;

        for (int num : nums) {
            int sum = digitSum(num);
            if (hash.find(sum) != hash.end()) {
                maxSum = max(maxSum, hash[sum] + num);
            }
            hash[sum] = max(hash[sum], num);
        }
        return maxSum;
    }
};