class Solution {
    bool symmeteric(TreeNode * p, TreeNode * q){
        if(!p || !q) return p == q;
        return (p->val == q->val) && symmeteric(p->left, q->right) && symmeteric(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || symmeteric(root->left, root->right);
    }
};