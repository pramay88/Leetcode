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
class Solution {
    void preOrder(TreeNode * node, vector<int> & res){
        if(!node){
            res.push_back(INT_MIN);
            return;
        }
        res.push_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> res1, res2;
        preOrder(p, res1);
        preOrder(q, res2);
        for(int i = 0; i < res1.size(); i++){
            if(res1[i] != res2[i]) return false;
        }
        return true;
    }
};