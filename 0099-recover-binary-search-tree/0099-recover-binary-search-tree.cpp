class Solution {
    void inorder(TreeNode * root, vector<TreeNode*> &in){
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> in;
        TreeNode *p = NULL, *q = NULL;
        inorder(root, in);

        for(int i = 1; i < in.size(); i++){
            if(in[i]->val < in[i - 1]->val){
                if(!p) p = in[i-1];
                q = in[i];
            }
        }
        swap(p->val, q->val);
    }
};