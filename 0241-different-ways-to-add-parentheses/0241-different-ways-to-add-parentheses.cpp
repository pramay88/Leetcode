class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n=expression.length();
        for(int i=0;i<n;i++){
            char c=expression[i];
            if(c=='+' || c=='-' || c=='*'){
                
                vector<int> left=diffWaysToCompute( expression.substr(0,i));
                vector<int> right=diffWaysToCompute( expression.substr(i+1,n-i-1));

                for(int l: left){
                    for(int r: right){
                        if(c=='+')  ans.push_back(l+r);
                        else if(c=='-') ans.push_back(l-r);
                        else    ans.push_back(l*r);
                    }
                }
            }
        }
        if(ans.empty())
            ans.push_back(stoi(expression));
        return ans;
    }
};