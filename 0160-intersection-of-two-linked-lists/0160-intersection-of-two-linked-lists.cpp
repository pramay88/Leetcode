/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        
        ListNode *a = headA, *b = headB;
        while(a){
            hash.insert(a);
            a = a->next;
        }
        
        while(b){
            if(hash.count(b)) return b;
            b = b->next;
        }

        return NULL;
    }
};