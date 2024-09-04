class Solution {
public:
    int cv(string s){
        int sum=0;
        for(const char c:s){
            int x=c-'a'+1;
            sum+=x<10?x:(x%10+x/10);
        }
        return sum;
    }
    int getSum(int num){
        int ds=0;
        while(num>0){
            ds+=num%10;
            num/=10;
        }
        return ds;
    }
    int getLucky(string s, int k) {
        int answer=cv(s);
        for(int i=1;i<k;++i){
            answer=getSum(answer);
        }
        return answer;
    }
};