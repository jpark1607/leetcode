/* Problem 104. Maximum Depth of Binary Tree
 * https://leetcode.com/submissions/detail/565649402/
 * 1. 문제:
 *   tree의 최대 depth를 구하여라.
 *
 * 2. 아이디어:
 *   NULL일 경우 0, 아닐 경우 자신의 하위 left와 right 각각을 구한 것 중 max에 +1하여 return하는 것을 recursive로 처리한다.
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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};