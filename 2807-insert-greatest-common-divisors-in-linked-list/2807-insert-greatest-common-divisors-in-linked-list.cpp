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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*temp=head;
        for(ListNode*curr=head->next;curr;curr=curr->next){
            int x=gcd(temp->val,curr->val);
            temp->next=new ListNode(x,curr);
            temp=curr;
        }
        return head;
    }
};