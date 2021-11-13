/* Problem 1038. Binary Search Tree to Greater Sum Tree
 * https://leetcode.com/submissions/detail/586348426/
 * 1. 문제:
 *   주어진 BST를 GST(오른쪽 노드부터 자기 자신, 왼쪽 노드의 합을 누적시킨 값)로 만들어라.
 *
 * 2. 아이디어:
 *   오른쪽 노드부터 탐색한 뒤 합의 누적을 구하고, 자기 자신을 탐색한 뒤 왼쪽 노드로 탐색한다.
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
    void makeSum(TreeNode *node, int &val) {
        if (!node)
            return;

        makeSum(node->right, val);

        node->val += val;
        val = node->val;

        makeSum(node->left, val);

        return;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;

        makeSum(root, val);

        return root;
    }
};