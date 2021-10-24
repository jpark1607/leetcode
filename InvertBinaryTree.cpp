/* Problem 226. Invert Binary Tree
 * https://leetcode.com/submissions/detail/576312485/
 * 1. 문제:
 *   주어진 tree의 좌우를 뒤집어라.
 *
 * 2. 아이디어:
 *   child부터 따라가면서 left와 right를 바꿔주고, 다시 부모로 나와 left와 right를 바꿔주는 작업을 반복한다(recursion).
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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *tmp;

        if (!root)
            return NULL;

        invertTree(root->left);
        invertTree(root->right);

        tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};