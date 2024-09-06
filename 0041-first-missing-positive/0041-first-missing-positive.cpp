class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]<=0 || nums[i]>=len+1)    nums[i]=len+1;
        }
        for(int i=0;i<len;i++){
            if(abs(nums[i])==len+1) continue;
            int pos=abs(nums[i])-1;
            if(nums[pos]>0) nums[pos]=-1*nums[pos];
        }
        for(int i=0;i<len;i++){
            if(nums[i]>0)   return i+1;
        }
        return len+1;
    }
};