class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        int len = 0;
        
        while(fast && fast->next){
            slow = slow->next;
            len++;
            fast = fast->next->next;
        }

        vector<int> sums(len, 0);
        int i = 0;
        fast = slow;
        slow = head;
        
        while(fast){
            sums[i] += slow->val;
            sums[len - i - 1] += fast->val;
            i++;
            slow = slow->next;
            fast = fast->next;
        }

        int maxx = 0;
        for(int n : sums) maxx = max(maxx, n);

        return maxx;
    }
};