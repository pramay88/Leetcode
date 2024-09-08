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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        for(ListNode*curr=head;curr!=NULL;curr=curr->next){
            ++len;
        }
        int count=len/k;
        int m=len%k;
        vector<ListNode*> split(k,NULL);
        ListNode *temp=head;
        for (int i = 0; i < k && temp != nullptr; ++i) {
            split[i] = temp;
            int x = count + (i < m ? 1 : 0);
            for (int j = 1; j < x; ++j) {
                temp = temp->next;
            }
            ListNode* nxt = temp->next;
            temp->next = nullptr;
            temp = nxt;
        }
        return split;
    }
};