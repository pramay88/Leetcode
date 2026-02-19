class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            int curr = root->val;
            
            if(p->val < curr && q->val < curr)
                root = root->left;
            
            else if(p->val > curr && q->val > curr)
                root = root->right;
            
            else return root;
        }
        return NULL;
    }
};