/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    TreeNode* myroot;
    TreeNode* _FindElements(TreeNode* node, int v){
        node->val = v;
        if(node->left) _FindElements(node->left, v*2+1);
        if(node->right) _FindElements(node->right, v*2+2);
        return node;
    };
    bool _find(int target, TreeNode* node){
        if(target == node->val) return true;
        bool found = false;
        if(node->left) found = found | _find(target, node->left);
        if(node->right) found = found | _find(target, node->right);
        return found;
    }
    FindElements(TreeNode* root) {
        myroot = _FindElements(root, 0);
    }
    
    bool find(int target) {
        if(!myroot) return false;
        return _find(target, myroot);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */