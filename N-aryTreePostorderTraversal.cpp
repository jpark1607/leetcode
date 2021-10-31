/* Problem 590. N-ary Tree Postorder Traversal
 * https://leetcode.com/submissions/detail/579824115/
 * 1. 문제:
 *
 *
 * 2. 아이디어:
 *
 *
 * 3. 상세 코드:
 *   [A]
 *     [A-1]
 *   [B]
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

        for (it = node->children.begin(); it != node->children.end(); it++)
            getNodeVal(res, *it);

        res.push_back(node->val);

        return;
    }

    vector<int> postorder(Node* root) {
        vector<int> res;

        getNodeVal(res, root);

        return res;
    }
};