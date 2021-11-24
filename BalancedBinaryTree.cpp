/* Problem 110. Balanced Binary Tree
 * https://leetcode.com/submissions/detail/592065108/
 * 1. 문제:
 *   주어진 Binary Tree가 balance한지 확인하여라.
 *   balance는 특정 노드를 기준으로 좌우의 레벨이 2개 이상 차이나서는 안 된다.
 *
 * 2. 아이디어:
 *   leaf부터 1씩 더해 가며 level을 return하고, node에서는 좌우를 비교해 본다.
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
    int checkChildLevel(TreeNode *node, bool &balanced) {
        int left, right;

        if (!node)
            return 0;

        left = checkChildLevel(node->left, balanced);
        if (!balanced)
            return -1;

        right = checkChildLevel(node->right, balanced);
        if (!balanced)
            return -1;

        if (right > left)
            swap(left, right);

        if (left - right > 1) {
            balanced = false;
            return -1;
        }

        return left;
    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;

        checkChildLevel(root, balanced);

        return balanced;
    }
};