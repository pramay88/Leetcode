class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushToStack(root);        
    }

    void pushToStack(TreeNode * node){
        while(node) st.push(node), node = node->left;
    }
    
    int next() {
        TreeNode * node = st.top(); st.pop();
        pushToStack(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};