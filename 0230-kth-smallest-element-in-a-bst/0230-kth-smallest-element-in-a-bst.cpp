class Solution {
    int ans = -1;
    void inorder(TreeNode * node, int &k){
        if(!node) return;
        inorder(node->left, k);
        k--;
        if(k == 0){
            ans = node->val;
            return;
        }
        inorder(node->right, k);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        inorder(root, k);
        return ans;
    }
};