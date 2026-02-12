class Solution {
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if(!root) return false;

        path.push_back(root);

        if(root == target) return true;

        if(getPath(root->left, target, path) || getPath(root->right, target, path))
            return true;

        path.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        getPath(root, p, path1);
        getPath(root, q, path2);

        TreeNode* lca = nullptr;

        int len = min(path1.size(), path2.size());
        
        for(int i = 0; i < len; i++){
            if(path1[i] == path2[i]) lca = path1[i];
            else break;
        }

        return lca;
    }
};