class Solution {
    void subsequence(int i, vector<int> &arr, vector<int> &sub, vector<vector<int>> &ans, int target){
        if(i >= arr.size()){
            if(target == 0) ans.push_back(sub);
            return; 
        }
        if(arr[i] <= target){
            sub.push_back(arr[i]);
            subsequence(i, arr, sub, ans, target - arr[i]);
            sub.pop_back();
        }
        subsequence(i + 1, arr, sub, ans, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;    
        vector<vector<int>> res;
        subsequence(0, candidates, sub, res, target);
        return res;
    }
};