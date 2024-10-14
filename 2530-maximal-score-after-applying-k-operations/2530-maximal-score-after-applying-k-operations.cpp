class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int> maxHeap(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            int maxx = maxHeap.top();
            maxHeap.pop();
            score+=maxx;
            maxHeap.push(ceil(maxx/3.0));
        }
        return score;
    }
};