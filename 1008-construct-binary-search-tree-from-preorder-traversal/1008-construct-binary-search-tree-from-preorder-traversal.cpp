class Solution {
    int start = 0;
    TreeNode * build(vector<int> & pre, int ub){
        if(start >= pre.size() || pre[start] > ub) return NULL;

        TreeNode * node = new TreeNode(pre[start++]);

        node->left = build(pre, node->val);
        node->right = build(pre, ub);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};