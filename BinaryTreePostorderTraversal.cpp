/* Problem 145. Binary Tree Postorder Traversal
 * https://leetcode.com/submissions/detail/566293213/
 * 1. 문제:
 *   postorder traversal 하면서 value들을 vector에 넣어 return하여라.
 *
 * 2. 아이디어:
 *   후위 순회 방식(left->right->node)대로 vector에 값을 넣는다.
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

        inputValue(node->left, result);
        inputValue(node->right, result);
        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        if (!root)
            return res;

        inputValue(root, res);

        return res;
    }
};