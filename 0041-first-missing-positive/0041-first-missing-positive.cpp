class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]<=0 || nums[i]>=len+1)    nums[i]=len+1;
        }
        for(int i=0;i<len;i++){
            int element=abs(nums[i]);
            if(element==len+1) continue;
            int pos=element-1;
            if(nums[pos]>0) nums[pos]=-1*nums[pos];
        }
        for(int i=0;i<len;i++){
            if(nums[i]>0)   return i+1;
        }
        return len+1;
    }
};