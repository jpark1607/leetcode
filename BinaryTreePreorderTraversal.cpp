/* Problem 144. Binary Tree Preorder Traversal
 * https://leetcode.com/submissions/detail/566291395/
 * 1. 문제:
 *   preorder traversal 하면서 value들을 vector에 넣어 return하여라.
 *
 * 2. 아이디어:
 *   전위 순회 방식(node->left->right)대로 vector에 값을 넣는다.
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
    void inputValue(TreeNode *node, vector<int> &result) {
        if (!node)
            return;

        result.push_back(node->val);
        inputValue(node->left, result);
        inputValue(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;

        if (!root)
            return res;

        inputValue(root, res);

        return res;
    }
};