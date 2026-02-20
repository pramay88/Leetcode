class Solution {
    TreeNode * build(vector<int> & pre, int start, int end){
        if(start > end) return NULL;
        TreeNode * node = new TreeNode(pre[start]);

        int partition = start + 1;
        while(partition <= end && pre[partition] < pre[start]) partition++;

        node->left = build(pre, start + 1, partition - 1);
        node->right = build(pre, partition, end);
        
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};