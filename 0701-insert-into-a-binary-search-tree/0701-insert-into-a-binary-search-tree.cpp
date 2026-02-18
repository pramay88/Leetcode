class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * node = new TreeNode(val), *curr = root;
        if(!root) return node;
        
        while(curr){
            if(curr->val > val){
                if(curr->left == NULL){
                    curr->left = node;
                    break;
                }
                curr = curr->left;
            }
            else{
                if(curr->right == NULL){
                    curr->right = node;
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
};