class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result;

        for(char c : s){
            if(c == '('){
                if(!st.empty()) result += c;
                st.push(c);
            }
            else{
                st.pop();
                if(!st.empty()) result += c;
            }
        }

        return result;
    }
};