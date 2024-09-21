class Solution {
public:
    int checkAdjacent(vector<char> c,int i){
        if (i >= c.size()) return 0;
        char ch=c[i];
        int len=0;
        while( i<c.size() && c[i]==ch ){
            len++;
            i++;
        }
        return len;
    }
    int compress(vector<char>& chars) {
        int len=chars.size();        
        int i=0,j=0;
        while(i<len){
            chars[j]=chars[i];
            int count=checkAdjacent(chars,i);
            if (count > 1) {
                string countStr = to_string(count);
                for (char digit : countStr) {
                    chars[++j] = digit;
                }
            }
            i+=count;
            j++;
        }
        chars.resize(j);
        return chars.size(); 
    }
};