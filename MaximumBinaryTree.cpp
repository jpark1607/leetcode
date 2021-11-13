/* Problem 654. Maximum Binary Tree
 * https://leetcode.com/submissions/detail/586370836/
 * 1. 문제:
 *   주어진 vector의 순서 그대로 binary tree를 만들어라.
 *
 * 2. 아이디어:
 *   vector에서 가장 큰 숫자를 찾고 이를 node로 만든 뒤, 그 idx를 전후하여 left와 right를 만드는 것을 반복한다.
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
    TreeNode *makeTree(vector<int> &nums, int l, int r) {
        TreeNode *node = NULL;
        int max = -1, idx = -1;
        int i;

        if (l > r)
            return NULL;

        for (i = l; i <= r; i++) {
            if (nums[i] > max) {
                idx = i;
                max = nums[i];
            }
        }

        node = new TreeNode(max);

        node->left = makeTree(nums, l, idx - 1);
        node->right = makeTree(nums, idx + 1, r);

        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return makeTree(nums, 0, nums.size() - 1);
    }
};