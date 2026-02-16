class Solution {
    TreeNode * buildTree(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &inMap){
        
        // no nodes left to construct
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode * root = new TreeNode(pre[preStart]);
        
        int inRoot = inMap[root->val];      // root position in inorder
        int leftNodes = inRoot - inStart;   // Nodes on left of root in inorder

        root->left = buildTree(pre, preStart + 1, preStart + leftNodes, 
                               in, inStart, inRoot - 1, inMap);
        
        root->right = buildTree(pre, preStart + leftNodes + 1, preEnd,
                                in, inRoot + 1, inEnd, inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int> inorderMap;
        
        for(int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        
        TreeNode * root = buildTree(preorder, 0, preorder.size() - 1,
                                    inorder, 0, inorder.size() - 1,
                                    inorderMap);
        return root;
    }
};