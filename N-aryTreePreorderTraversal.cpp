/* Problem 589. N-ary Tree Preorder Traversal
 * https://leetcode.com/submissions/detail/579822804/
 * 1. 문제:
 *   N개의 children을 가지는 Tree를 전위 순회하여 값들을 vector에 넣어 return 하여라.
 *
 * 2. 아이디어:
 *   X
 * */
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
    void getNodeVal(vector<int> &res, Node *node) {
        vector<Node *>::iterator it;

        if (!node)
            return;

        res.push_back(node->val);

        for (it = node->children.begin(); it != node->children.end(); it++)
            getNodeVal(res, *it);

        return;
    }

    vector<int> preorder(Node* root) {
        vector<int> res;

        getNodeVal(res, root);

        return res;
    }
};