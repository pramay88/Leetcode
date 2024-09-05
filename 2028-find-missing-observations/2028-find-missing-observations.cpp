class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int ss=(n+m)*mean-(accumulate(rolls.begin(),rolls.end(),0));
        if(ss>n*6 || ss<n)    return {};
        vector<int> a(n,ss/n);
        for(int i=0;i<ss%n;++i) 
            ++a[i];
        return a;
    }
};