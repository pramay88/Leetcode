class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0,j=0;
        for(int x=0;x<commands.size();x++){
            if(commands[x]=="RIGHT")
                j++;
            if(commands[x]=="DOWN")
                i++;
            if(commands[x]=="LEFT")
                j--;
            if(commands[x]=="UP")
                i--;
        }
        return (i*n)+j;
    }
};