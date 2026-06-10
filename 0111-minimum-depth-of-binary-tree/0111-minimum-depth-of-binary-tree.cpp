class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(root->left == NULL && root->right == NULL) return 1;

        int left = (root->left != NULL)? minDepth(root->left): INT_MAX;
        int right = (root->right != NULL)? minDepth(root->right): INT_MAX;

        return 1 + min(left, right);
    }
};