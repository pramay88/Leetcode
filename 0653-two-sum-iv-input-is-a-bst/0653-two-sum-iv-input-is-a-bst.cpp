class BSTIterator{
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode * node){
        while(node != NULL){
            st.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }

public:
    BSTIterator(TreeNode * root, bool reverse){
        this->reverse = reverse;
        pushAll(root);
    }
    
    int next(){
        TreeNode *temp = st.top();
        st.pop();
        if(reverse == true) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->val;
    }

    bool hasNext(){
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false), r(root, true);

        int left = l.next(), right = r.next();
        while(left < right){
            if(left + right == k) return true;
            else if(left + right > k) right = r.next();
            else left = l.next();
        }
        return false;
    }
};