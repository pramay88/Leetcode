/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> a;
        stack<Node*> stck;
        stck.push(root);
        while(!stck.empty()){
            Node* node=stck.top();
            stck.pop();
            if(node==NULL)  continue;
            for(Node* ch:node->children){
                stck.push(ch);
            }
            a.insert(a.begin(),node->val);
        }
        return a;
    }
};