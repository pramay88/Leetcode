class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(),false);
        int max=0;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>max)
                max=candies[i];
        }   
        for(int j=0;j<candies.size();j++){
            if(candies[j]+extraCandies>=max)
                ans[j]=true;
            else    ans[j]=false;
        }
        return ans;
    }
};