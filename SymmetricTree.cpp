/* Problem 101. Symmetric Tree
 * https://leetcode.com/submissions/detail/566250183/
 * 1. 문제:
 *   tree가 root를 기준으로 좌우 대칭인지 확인하여라.
 *
 * 2. 아이디어:
 *   2-1. recursive로 확인하되, left와 right의 child 탐색을 대칭으로 한다.
 *   2-2. iterative 고민해보자.
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
#define RESOLUTION 0 /* 0 as recursive, 1 as iterative */

class Solution {
public:
    bool checkSymmetricRecursive(TreeNode *l, TreeNode *r) {
        if (!l && !r)
            return true;
        else if ((l && !r) || (!l && r))
            return false;
        else if (l->val != r->val)
            return false;
        else if (!checkSymmetricRecursive(l->left, r->right))
            return false;
        else if (!checkSymmetricRecursive(l->right, r->left))
            return false;

        return true;
    }

    bool checkSymmetricIterative(TreeNode *root) {
        /* TODO */
        return true;
    }

    bool isSymmetric(TreeNode *root) {

        if (RESOLUTION)
            return checkSymmetricRecursive(root->left, root->right);
        else
            return checkSymmetricIterative(root);
    }
};