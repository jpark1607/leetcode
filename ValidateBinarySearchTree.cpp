/* Problem 98. Validate Binary Search Tree
 * https://leetcode.com/submissions/detail/592061193/
 * 1. 문제:
 *   주어진 Binary Search Tree가 유효한지 검사하여라.
 *
 * 2. 아이디어:
 *   left, right를 계속 갱신하면서 tree 탐색을 한다.
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
    bool checkValid(TreeNode *node, long left, long right) {
        bool chk = true;

        if ((long)node->val <= left || (long)node->val >= right)
            return false;

        if (node->left) {
            chk = checkValid(node->left, left, (long)node->val);
            if (!chk)
                return false;
        }

        if (node->right) {
            chk = checkValid(node->right, (long)node->val, right);
            if (!chk)
                return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return checkValid(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};