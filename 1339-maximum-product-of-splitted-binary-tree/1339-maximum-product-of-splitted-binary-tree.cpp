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
    long long totalSum = 0, maxProd = 0;
    long long getTotalSum(TreeNode *root){
        if(!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }
    long long dfs(TreeNode *root){
        if(!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long sum = root->val + left + right;
        long long prod = sum * (totalSum - sum);
        maxProd = max(maxProd, prod);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProd % int(1e9 + 7);
    }
};