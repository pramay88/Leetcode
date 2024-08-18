class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    string s(word1.length()+word2.length(),'z');
    int i,j=0,k=0;
    int size=(word1.length()>=word2.length())?word2.length():word1.length();
    for(i=0;i<2*size;i++){
        if(i%2==0){
            s[i]=word1[j];
            j++;
        }
        else{
            s[i]=word2[k];
            k++;
        }
    }
    if(word1.length()>word2.length()){
        for(;i<s.length();i++,j++){
            s[i]=word1[j];
        }
    }
    else{
        for(;i<s.length();i++,k++){
            s[i]=word2[k];
        }
    }
    return s;
}
};