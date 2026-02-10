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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int leftToRight = true;

        while(!q.empty()){
            int levelSize = q.size();
            deque<int> dq;

            for(int i = 0; i < levelSize; i++){
                TreeNode * node = q.front(); q.pop();
                
                if(leftToRight) dq.push_back(node->val);
                else dq.push_front(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.emplace_back(dq.begin(), dq.end());
            leftToRight = !leftToRight;
        }
        return res;
    }
};