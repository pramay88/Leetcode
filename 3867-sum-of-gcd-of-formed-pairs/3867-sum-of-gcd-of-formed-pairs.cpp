class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> values;
        values.reserve(nums.size());

        int prefixMax = 0;

        for(int num : nums){
            prefixMax = max(prefixMax, num);
            values.push_back(gcd(num, prefixMax));
        }

        std::sort(values.begin(), values.end());

        long long answer = 0;
        int left = 0, right = values.size() - 1;

        while(left < right){
            answer += gcd(values[left], values[right]);
            ++left;
            --right;
        }

        return answer;
    }
};