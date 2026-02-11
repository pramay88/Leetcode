class Solution {
    vector<string> res;    
    void paths(TreeNode * node, string s){
        s += to_string(node->val);
        if(!node->left && !node->right){
            res.push_back(s);
            return;
        }
        s += "->";
        if(node->left) paths(node->left, s);
        if(node->right) paths(node->right, s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        string s;
        paths(root, s);
        return res;
    }
};