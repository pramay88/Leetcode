class Solution {
    void findCombinations(int i, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds){
        if(i == arr.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        if(arr[i] <= target){
            ds.push_back(arr[i]);
            findCombinations(i, arr, target - arr[i], ans, ds);
            ds.pop_back();
        }
        findCombinations(i+1, arr, target, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};