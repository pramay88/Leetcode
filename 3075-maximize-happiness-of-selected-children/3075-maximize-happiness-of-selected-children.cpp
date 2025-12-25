class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        int n = min((int)happiness.size(), k);
        long long maxCount = 0;
        
        for(int i = 0; i < n; i++){
            int h = happiness[i] - i;
            if(h > 0) maxCount += h;  
            else break;
        }
        return maxCount;
    }
};