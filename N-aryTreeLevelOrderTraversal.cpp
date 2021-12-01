/* Problem 429. N-ary Tree Level Order Traversal
 * https://leetcode.com/submissions/detail/595469004/
 * 1. 문제:
 *   n개의 children을 갖는 tree가 있을 때, 각 node의 level 순서대로 vector에 모아 return하여라.
 *
 * 2. 아이디어:
 *   자식을 따라갈 때마다 level + 1을 해 준다.
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
private:
    vector<vector<int>> v;
    int lvl;
public:
    void traverseTree(Node *node, int level) {
        if (!node)
            return;

        if (this->lvl < level) {
            vector<int> n(1, node->val);
            this->v.push_back(n);
            this->lvl++;
        }
        else
            v[level].push_back(node->val);

        for (int i = 0; i < node->children.size(); i++) {
            traverseTree(node->children[i], level + 1);
        }

        return;
    }

    vector<vector<int>> levelOrder(Node* root) {
        this->lvl = -1;

        traverseTree(root, 0);

        return this->v;
    }
};