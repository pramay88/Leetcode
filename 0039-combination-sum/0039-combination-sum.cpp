class Solution {
    void subsequence(int i, vector<int> &arr, vector<int> &sub, vector<vector<int>> &comb, int target){
        if(target == 0){
            comb.push_back(sub);
            return;
        }
        if(i >= arr.size() || target < 0) return;

        sub.push_back(arr[i]);
        subsequence(i, arr, sub, comb, target - arr[i]);
        
        sub.pop_back();
        subsequence(i + 1, arr, sub, comb, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;    
        vector<vector<int>> res;
        subsequence(0, candidates, sub, res, target);
        return res;
    }
};