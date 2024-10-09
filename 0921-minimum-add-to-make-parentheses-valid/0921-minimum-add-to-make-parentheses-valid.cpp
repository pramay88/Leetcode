class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,count=0;
        for(char c: s){
            if(c=='(')
                ++count;
            else if(count)
                --count;
            else
                ans++;
        }
        ans+=count;
        return ans;
    }
};