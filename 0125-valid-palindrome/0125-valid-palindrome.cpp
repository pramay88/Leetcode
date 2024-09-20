class Solution {
public:
    bool isValid(char c){
        if( (c>='a' && c<='z') || (c>='0' && c<='9') )
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        string temp;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]>='A' && s[i]<='Z')  
                s[i]=s[i] -'A'+'a';
            if(isValid(s[i]))
                temp+=s[i];
        }
        len=temp.length();
        for(int i=0;i<len;i++){
            if(temp[i]!=temp[len-i-1])
                return false;
        }
        return true;
    }
};