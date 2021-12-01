/* Problem 404. Sum of Left Leaves
 * https://leetcode.com/submissions/detail/595456039/
 * 1. 문제:
 *   left leaf node의 값의 합을 구하여라.
 *
 * 2. 아이디어:
 *   child가 없고 left인 경우만 합산한다.
 *   (parent node에서 left node로 갈 때 boolean 값을 true로 해 준다)
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
private:
    int sum;
public:
    void calcSum(TreeNode *node, bool isLeft) {
        if (!node)
            return;

        if (!node->left && !node->right) {
            if (isLeft)
                this->sum += node->val;
            else
                return;
        }

        calcSum(node->left, true);
        calcSum(node->right, false);

        return;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        this->sum = 0;

        calcSum(root, false);

        return this->sum;
    }
};