/* Problem 94. Binary Tree Inorder Traversal
 * recursive : https://leetcode.com/submissions/detail/568327343/
 * iterative : https://leetcode.com/submissions/detail/568334978/
 * 1. 문제:
 *   주어진 tree를 중위순회하여 배열로 반환하여라.
 *
 * 2. 아이디어:
 *   2-1. recursive
 *   2-2. iterative
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
    void recursiveTraversal(TreeNode *node, vector<int> &res) {
        if (!node)
            return;

        recursiveTraversal(node->left, res);
        res.push_back(node->val);
        recursiveTraversal(node->right, res);
    }

    void iterativeTraversal(TreeNode *node, vector<int> &res) {
        stack<TreeNode *> st;
        TreeNode *cur = node;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();

            res.push_back(cur->val);
            cur = cur->right;
        }

        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        bool is_recur = true;

        if (is_recur)
            recursiveTraversal(root, res);
        else
            iterativeTraversal(root, res);

        return res;
    }
};