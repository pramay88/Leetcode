class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        vector<char> vovels={'a','e','i','o','u'};
        int msk=1;
        for(char c: vovels){
            mp[c]=msk;
            msk=msk*2;
        }
        msk=0;
        int ans=0;
        vector<int> seen(32,-1);
        for(int i=0;i<n;i++){
            auto it=mp.find(s[i]);
            if(it!=mp.end())
                msk^=it->second;
            else
                msk^=0;
            if(seen[msk]==-1 && msk!=0)
                seen[msk]=i;
            ans=max(ans,i-seen[msk]);
        }
        return ans;
    }
};