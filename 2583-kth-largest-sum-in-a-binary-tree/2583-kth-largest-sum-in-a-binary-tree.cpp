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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> vec;
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            long long t=0;
            for(int i=q.size(); i; --i){
                root = q.front();
                q.pop();
                t += root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            vec.push_back(t);
        }
        if (vec.size() < k) {
            return -1;
        }
        sort(vec.rbegin(), vec.rend());
        return vec[k - 1];

    }
};