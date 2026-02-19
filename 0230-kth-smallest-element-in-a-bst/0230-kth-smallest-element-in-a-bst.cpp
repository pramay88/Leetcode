class Solution {
    int inorder(TreeNode * node, int &k){
        if(!node) return -1;
        
        int left = inorder(node->left, k);
        if(left != -1) return left;
        
        k--;
        if(k == 0) return node->val;
        
        return inorder(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};