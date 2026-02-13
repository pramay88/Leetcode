class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> kNodes;
        if(!root) return kNodes;

        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();

            TreeNode *left = NULL, *right = NULL;
            
            if(node->left) left = node->left, parent[left] = node;
            if(node->right) right = node->right, parent[right] = node;
            
            if(left) q.push(left);
            if(right) q.push(right);
        }

        queue<pair<TreeNode*, int>> qq;
        unordered_map<TreeNode*, int> vis;
        qq.push({target, 0});
        
        while(!qq.empty()){
            auto [node, dist] = qq.front();
            qq.pop();

            if(vis[node] >= 1) continue;
            vis[node]++;
            
            if(dist == k){
                kNodes.push_back(node->val);
                continue;
            }

            if(node->left) qq.push({node->left, dist + 1});
            if(node->right) qq.push({node->right, dist + 1});
            if(parent[node]) qq.push({parent[node], dist + 1});
        }
        return kNodes;
    }
};