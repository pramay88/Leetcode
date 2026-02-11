class Solution {
    bool symmeteric(TreeNode * p, TreeNode * q){
        if(!p || !q) return p == q;
        if(p->val != q->val) return false;
        return symmeteric(p->left, q->right) && symmeteric(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return symmeteric(root->left, root->right);
    }
};