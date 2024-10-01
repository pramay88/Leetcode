class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k,0);
        for(int num : arr){
            ++count[((num % k) + k) % k];
        }
        if(count[0]%2 != 0)
            return false;

        for (int i = 1; i < k; ++i) {
            if (count[i] != count[k - i]) {
                return false;
            }
        }
        return true;
    }
};