/* Problem 111. Minimum Depth of Binary Tree
 * https://leetcode.com/submissions/detail/571175031/
 * 1. 문제:
 *   주어진 binary tree에서 depth가 최소인 값을 구하여라.
 *
 * 2. 아이디어:
 *   다 따라가본다.
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        else {
            if (!root->left)
                return minDepth(root->right) + 1;
            else if (!root->right)
                return minDepth(root->left) + 1;
            else
                return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
        }
    }
};