class Solution {
    void preOrder(TreeNode * root, vector<TreeNode*> & pre){
        if(!root) return;
        pre.push_back(root);
        preOrder(root->left, pre);
        preOrder(root->right, pre);
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        vector<TreeNode*> nodes;
        preOrder(root, nodes);
        
        for(int i = 0; i < nodes.size() - 1; i++){
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i + 1];
        }
        
        nodes.back()->left = NULL;
        nodes.back()->right = NULL;        
    }
};