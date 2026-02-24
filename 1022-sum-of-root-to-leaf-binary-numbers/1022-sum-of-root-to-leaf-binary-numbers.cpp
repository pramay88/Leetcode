class Solution {
    int inorder(TreeNode * node, int curr){
        if(!node) return 0;
        curr = (curr << 1) | node->val;

        if(!node->left && !node->right)
            return curr;

        return inorder(node->left, curr) + inorder(node->right, curr);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return inorder(root, 0);
    }
};