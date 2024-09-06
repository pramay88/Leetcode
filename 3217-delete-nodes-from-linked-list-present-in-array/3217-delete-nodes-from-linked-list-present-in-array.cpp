/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void DeleteNode(ListNode*head){
        
        ListNode*temp=head;
        temp->next=NULL;

    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode *temp=new ListNode(0,head);
        for(ListNode *prev=temp;prev->next;){
            if(st.count(prev->next->val))
                prev->next=prev->next->next;
            else    prev=prev->next;
        }
    return temp->next;
     
    }
};