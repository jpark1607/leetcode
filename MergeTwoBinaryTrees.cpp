/* Problem 617. Merge Two Binary Trees
 * https://leetcode.com/submissions/detail/579805522/
 * 1. 문제:
 *
 *
 * 2. 아이디어:
 *
 *
 * 3. 상세 코드:
 *   [A]
 *     [A-1]
 *   [B]
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
    TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2) {
        TreeNode *root = NULL;

        if (!root1 && !root2)
            return NULL;

        root = new TreeNode((root1 ? root1->val : 0) + (root2 ? root2->val : 0));

        root->left = mergeTrees((root1 ? root1->left : NULL), (root2 ? root2->left : NULL));
        root->right = mergeTrees((root1 ? root1->right : NULL), (root2 ? root2->right : NULL));

        return root;
    }
};