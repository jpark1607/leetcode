/* Problem 897. Increasing Order Search Tree
 * https://leetcode.com/submissions/detail/593265719/
 * 1. 문제:
 *   주어진 tree를 중위 순회하여 leftmost tree로 만들어라.
 *
 * 2. 아이디어:
 *   중위 순회하여 stack에 넣고, pop하면서 밑에서부터 만들어간다.
 * */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode *node, stack<TreeNode *> &s) {
        if (node->left)
            traverse(node->left, s);

        s.push(node);

        if (node->right)
            traverse(node->right, s);

        return;
    }

    TreeNode *increasingBST(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *prev = NULL, *node = NULL;

        traverse(root, s);

        while (!s.empty()) {
            node = s.top();
            s.pop();

            node->left = NULL;
            node->right = prev;
            prev = node;
        }

        return node;
    }
};