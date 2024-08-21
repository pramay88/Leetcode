class Solution {
public:
    string reverseVowels(string s) {
        
        bool vovel[128]={false};
        for(char c: "aeiouAEIOU"){
            vovel[c]=true;
        }

        int i=0;
        int j=s.length()-1;
        
        while(i<j){
            while(i<j && !vovel[s[i]]){
                ++i;
            }
            while(i<j && !vovel[s[j]]){
                --j;
            }
            if(i<j){
                swap(s[i++],s[j--]);    
            }
        }
        return s;
    }
};