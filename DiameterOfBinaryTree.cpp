/* Problem 543. Diameter of Binary Tree
 * https://leetcode.com/submissions/detail/593930992/
 * 1. 문제:
 *   주어진 tree에서 가장 긴 경로의 길이를 구하여라.
 *
 * 2. 아이디어:
 *   밑에서부터 길이를 하나씩 올리면서, 각 노드마다 left + right의 값을 max와 비교해 본다.
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
private:
    int max_path;
public:
    int getChildLength(TreeNode *node) {
        int l = 0, r = 0;

        if (node->left)
            l = getChildLength(node->left);
        if (node->right)
            r = getChildLength(node->right);

        if (this->max_path < l + r + 1)
            this->max_path = l + r + 1;

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        this->max_path = 0;

        getChildLength(root);

        return this->max_path;
    }
};