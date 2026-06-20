class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while(curr && curr->next){
            if(curr->val == curr->next->val){
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else curr = curr->next;
        }

        return head;
    }
};