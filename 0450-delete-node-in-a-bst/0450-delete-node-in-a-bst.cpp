class Solution {
    TreeNode * helper(TreeNode * node){
        if(!node->left) return node->right;
        else if(!node->right) return node->left;
        
        TreeNode * rightChild = node->right;
        TreeNode * rightMost = findRightMost(node->left);
        rightMost->right = rightChild;
        return node->left;
    }
    TreeNode * findRightMost(TreeNode * node){
        while(node->right) node = node->right;
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) return helper(root);

        TreeNode * curr = root;

        while(curr){
            if(curr->val > key){
                if(curr->left != NULL && curr->left->val == key){
                    curr->left = helper(curr->left);
                    break;
                }
                else curr = curr->left;
            }
            else{
                if(curr->right != NULL && curr->right->val == key){
                    curr->right = helper(curr->right);
                }
                else curr = curr->right;
            }
        }
        return root;
    }
};