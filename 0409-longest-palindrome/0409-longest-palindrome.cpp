class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        vector<int> freq(128, 0);

        for(char c: s) freq[c]++;
        
        bool hasOdd = false;

        for(int &f: freq){
            if(f % 2 == 0) count += f;
            else{
                count += f - 1;
                hasOdd = true;
            }
        }

        return count + (hasOdd? 1: 0);
    }
};