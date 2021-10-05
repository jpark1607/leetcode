/* Problem 112. Path Sum
 * https://leetcode.com/submissions/detail/566266238/
 * 1. 문제:
 *   root부터 leaf까지의 합이 targetSum이 되는 path가 있는지 확인하여라.
 *   leaf는 left와 right child가 모두 없는 node이다.
 *
 * 2. 아이디어:
 *   탐색하는 node에서 target value를 뺀 뒤, left node이면서 target value가 0이면 true를 return한다.
 *   그 외에는 branch node이기 때문에 있는 child를 recursive로 탐색한다.
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
    bool checkPath(TreeNode* node, int targetVal) {
        targetVal -= node->val;

        if (!node->left && !node->right) {
            if (targetVal == 0)
                return true;
        }
        else {
            if (node->left && checkPath(node->left, targetVal))
                return true;
            else if (node->right && checkPath(node->right, targetVal))
                return true;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;

        return checkPath(root, targetSum);
    }
};