class Solution {
    void backtrack(vector<int> & arr, vector<vector<int>> & set, vector<int> & subset, int i){
        if(i == arr.size()){
            set.push_back(subset);
            return;
        }
        // Include
        subset.push_back(arr[i]);
        backtrack(arr, set, subset, i + 1);
        
        // Exclude
        subset.pop_back();
        backtrack(arr, set, subset, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> set;
        vector<int> subset;
        backtrack(nums, set, subset, 0);
        return set;
    }
};