class Solution {
    void inorder(TreeNode * node, vector<int> & in){
        if(!node) return;
        inorder(node->left, in);
        in.push_back(node->val);
        inorder(node->right, in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);

        int left = 0, right = in.size() - 1;
        while(left < right){
            if(in[left] + in[right] == k) return true;
            else if(in[left] + in[right] < k) left++;
            else right--;
        }
        
        return false;
    }
};