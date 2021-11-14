/* Problem 113. Path Sum II
 * https://leetcode.com/submissions/detail/586864276/
 * 1. 문제:
 *   주어진 tree의 root부터 leaf까지의 합이 target과 같은 경우를 모두 구하여라.
 *
 * 2. 아이디어:
 *   leaf까지 따라가면서 target의 값에서 빼고, leaf에서 target이 0인지 확인한다.
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
    void checkNode(TreeNode *node, vector<vector<int> > &res, vector<int> path, int target) {
        path.push_back(node->val);
        target -= node->val;

        if (!node->left && !node->right) {
            if (target == 0)
                res.push_back(path);
        }
        else {
            if (node->left)
                checkNode(node->left, res, path, target);
            if (node->right)
                checkNode(node->right, res, path, target);
        }

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        int sum = 0;

        if (root)
            checkNode(root, res, path, targetSum);

        return res;
    }
};