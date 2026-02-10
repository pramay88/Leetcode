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
    vector<vector<int>> res;
    void traverse(TreeNode * root){
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        bool reversal = false;
        
        while(!q.empty()){
            vector<int> level;
            int levelSize = q.size();
            
            for(int i = 0; i < levelSize; i++){
                TreeNode * node = q.front();
                q.pop();
                
                level.push_back(node->val);
            
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                }
            if(reversal){
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
            reversal = !reversal;
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root);
        return res;
    }
};