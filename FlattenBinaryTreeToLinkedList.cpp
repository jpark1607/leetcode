/* Problem 114. Flatten Binary Tree to Linked List
 * https://leetcode.com/submissions/detail/579337101/
 * 1. 문제:
 *   주어진 tree를 linked list로 바꾸되, 전위 탐색 방식으로 만들어라.
 *
 * 2. 아이디어:
 *   전위 탐색 하면서 right를 tmp에 놓고 left를 right에 놓은 뒤, tmp를 right 밑에 놓는 것을 recursive로 처리한다.
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
    void makeList(TreeNode *node) {
        TreeNode *tmp = NULL;

        if (node->left) {
            tmp = node->right;
            node->right = node->left;
            node = node->right;
            makeList(node);
        }

        if (tmp) {
            node->right = tmp;
            node = node->right;
            makeList(node);
        }
    }

    void flatten(TreeNode *root) {
        if (!root || (!root->left && !root->right))
            return;

        makeList(root);
    }
};