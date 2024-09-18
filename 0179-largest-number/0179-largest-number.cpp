class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> elements(n);
        for (int i = 0; i < n; i++) {
            elements[i] = to_string(nums[i]);
        }

        sort(elements.begin(), elements.end(), [](const string& a, const string& b) {
            return (b + a) < (a + b);
        });

        if (elements[0] == "0") {
            return "0";
        }

        string result;
        for (const string& val : elements) {
            result += val;
        }

        return result;
    }
};