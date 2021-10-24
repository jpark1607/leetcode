/* Problem 230. Kth Smallest Element in a BST
 * https://leetcode.com/submissions/detail/576314846/
 * 1. 문제:
 *   주어진 BST에서 k번째로 작은 수를 구하여라.
 *
 * 2. 아이디어:
 *   left, cur, right 순으로 따라간다.
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
    int findPos(TreeNode *node, int &nth, int k) {
        int res;
        if (!node)
            return -1;

        res = findPos(node->left, nth, k);
        if (res > -1)
            return res;

        nth++;
        if (nth == k)
            return node->val;

        res = findPos(node->right, nth, k);
        return res;
    }
    int kthSmallest(TreeNode *root, int k) {
        int nth = 0;
        return findPos(root, nth, k);
    }
};