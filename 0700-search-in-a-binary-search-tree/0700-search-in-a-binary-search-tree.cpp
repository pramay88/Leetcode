class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode * node = root;
        while(node){
            if(node->val == val) return node;
            else if(node->val > val) node = node->left;
            else node = node->right;
        }
        return NULL;
    }
};