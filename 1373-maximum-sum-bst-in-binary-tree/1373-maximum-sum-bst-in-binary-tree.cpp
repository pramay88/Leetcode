class Node{
public:
    int minNode, maxNode, sum;
    Node(int minNode, int maxNode, int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
    int maxSum = 0;

    Node postorder(TreeNode * node){
        if(!node) return Node(INT_MAX, INT_MIN, 0);

        auto left = postorder(node->left);
        auto right = postorder(node->right);
        
        if(left.maxNode < node->val && node->val < right.minNode){
            int currSum = left.sum + right.sum + node->val;
            maxSum = max(maxSum, currSum);

            return Node(
                min(node->val, left.minNode),
                max(node->val, right.maxNode),
                currSum
            );
        }
        
        return Node(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return maxSum;
    }
};