class Solution {
    TreeNode * p = NULL, * q = NULL, *prev = NULL;

    void inorder(TreeNode * root){
        if(!root) return;
        inorder(root->left);
        if(prev && (root->val < prev->val)){
            if(!p) p = prev;
            q = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(p->val, q->val);
    }
};