class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto [node, row] = q.front(); q.pop();
            
            if(mp.find(row) == mp.end())
                mp[row] = node->val;

            if(node->right) q.push({node->right, row + 1});
            if(node->left) q.push({node->left, row + 1});
        }
        for(auto [row, value]: mp)
            ans.push_back(value);
        return ans;
    }
};