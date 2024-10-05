class Solution {
public:
    bool checkEqual(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {

        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            count1[s1[i]-'a']++;
        }
        
        int i=0;
        int windowLen=s1.length();
        int count2[26]={0};
        // checkin for first window only
        while( i<windowLen && i<s2.length() ){
            count2[s2[i]-'a']++;
            i++;
        }
        if(checkEqual(count1,count2))
            return 1;

        while(i<s2.length()){
            
            char newChar=s2[i];
            count2[newChar-'a']++;

            char oldChar=s2[i-windowLen];
            count2[oldChar-'a']--;
            
            i++;
            
            if(checkEqual(count1,count2))
                return true;

        }
        return false;
    }
};