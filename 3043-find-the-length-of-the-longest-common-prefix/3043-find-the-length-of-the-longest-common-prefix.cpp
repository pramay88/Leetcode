class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> preSet;
        for(int x: arr1){
            while(x){
                preSet.insert(x);
                x/=10;
            }
        }
        int ans=0;
        for(int x: arr2){
            while(x>0){
                if(preSet.count(x)){
                    ans=max(ans,(int)log10(x)+1);
                    break;
                }
                x/=10;
            }
        }
        return ans;
    }
};