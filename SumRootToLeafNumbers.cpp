/* Problem 129. Sum Root to Leaf Numbers
 * https://leetcode.com/submissions/detail/592068477/
 * 1. 문제:
 *   root부터 각 leaf까지의 숫자들을 하나의 수라고 할 때, 모든 수들의 합을 구하여라.
 *
 * 2. 아이디어:
 *   따라가면서 더한다.
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
    void rootToLeaf(TreeNode *node, int num, int &sum) {
        num = num * 10 + node->val;

        if (!node->left && !node->right)
            sum += num;
        else {
            if (node->left)
                rootToLeaf(node->left, num, sum);

            if (node->right)
                rootToLeaf(node->right, num, sum);
        }

        return;
    }

    int sumNumbers(TreeNode *root) {
        int sum = 0;

        rootToLeaf(root, 0, sum);

        return sum;
    }
};