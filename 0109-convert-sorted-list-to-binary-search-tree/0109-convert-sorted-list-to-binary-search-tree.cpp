class Solution {
    TreeNode* build(vector<int> nums, int l, int r){
        if(l > r) return NULL;

        int m = l + (r - l)/2;
        TreeNode * root = new TreeNode(nums[m]);

        root->left = build(nums, l, m - 1);
        root->right = build(nums, m + 1, r);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }

        return build(nodes, 0, nodes.size() - 1);
    }
};