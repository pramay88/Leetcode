class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minDiff = abs(arr[0] - arr[1]);
        for(int i = 0; i < arr.size() - 1; i++){
            int diff = abs(arr[i] - arr[i + 1]);
            if(diff < minDiff){
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
            }
            else if(diff == minDiff) 
                ans.push_back({arr[i], arr[i + 1]});

        }
        return ans;
    }
};