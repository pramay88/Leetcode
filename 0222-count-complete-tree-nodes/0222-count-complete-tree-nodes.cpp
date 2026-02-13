class Solution {
    int leftHeight(TreeNode * node){
        int h = 0;
        while(node) h++, node = node->left;
        return h;
    }
    int rightHeight(TreeNode * node){
        int h = 0;
        while(node) h++, node = node->right;
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftH = leftHeight(root);
        int rightH = rightHeight(root);
        
        if(leftH == rightH)
            return (1 << leftH) - 1;    // 2^leftH - 1 
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};