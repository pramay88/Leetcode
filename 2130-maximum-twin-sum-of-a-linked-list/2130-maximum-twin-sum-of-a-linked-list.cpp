class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* node = head;
        int len = 0;

        while(node){
            len++;
            node = node->next;
        }

        vector<int> sums(len / 2, 0);
        node = head;

        int i = 0;
        while(i < len / 2){
            sums[i++] = node->val;
            node = node->next;
        }

        i = len / 2 - 1;
        while (node){
            sums[i--] += node->val;
            node = node->next;
        }

        int maxx = 0;
        for(int n : sums) maxx = max(maxx, n);

        return maxx;
    }
};