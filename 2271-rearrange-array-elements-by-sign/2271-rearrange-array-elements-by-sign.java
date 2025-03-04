class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int pos = 0, neg = 1;
        for(int num: nums){
            if(num >= 0){
                res[pos] = num;
                pos += 2;
            }
            else{
                res[neg] = num;
                neg += 2;
            }
        }
        return res;
    }
}