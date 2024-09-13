class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> arr1(arr.size()+1);
        vector<int> ans;
        arr1[0]=arr[0];
        for(int i = 1; i < arr.size(); i++){
            arr1[i] = arr1[i-1] ^ arr[i];
        }
        for(const vector<int> q: queries){
            int l=q[0];
            int r=q[1];
            int res=arr1[r];
            if(l>0) res ^= arr1[l-1];
            ans.push_back(res);
        }
        return ans;
    }
};