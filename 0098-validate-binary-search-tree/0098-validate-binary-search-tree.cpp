class Solution {
    long long prev = LLONG_MIN;
    int inorder(TreeNode * node){
        if(!node) return true;

        if(!inorder(node->left))
            return false;
            
        if(node->val <= prev) return false;
        prev = node->val;
        
        return inorder(node->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};