class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        // {col, {row, <sorted_values>}} 
        map<int, map<int, multiset<int>>> mp;
        
        // {node, {row, col}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            for(int i = 0; i < q.size(); i++){
                auto [node, coordinates] = q.front(); q.pop();
                auto [row, col] = coordinates;
                
                mp[col][row].insert(node->val);
                
                if(node->left) q.push({node->left, {row + 1, col - 1}});
                if(node->right) q.push({node->right, {row + 1, col + 1}});
            }
        }

        for(auto colPair: mp){
            vector<int> column;
            for(auto rowPair: colPair.second){
                for(auto value: rowPair.second)
                    column.push_back(value);
            }
            ans.push_back(column);
        }
        return ans;
    }
};