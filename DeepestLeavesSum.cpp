/* Problem 1302. Deepest Leaves Sum
 * https://leetcode.com/submissions/detail/571944374/
 * 1. 문제:
 *   root부터 가장 먼 위치의 leaf node들의 합을 구하여라.
 *
 * 2. 아이디어:
 *   따라가면서 가장 deep level을 구해놓고, 같으면 더해주고 더 deep한 것을 찾으면 새로 갱신해준다.
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
    void findLeafMakeSum(TreeNode *node, int curLevel, int &deepestLevel, int &sum) {
        if (node->left)
            findLeafMakeSum(node->left, curLevel + 1, deepestLevel, sum);
        if (node->right)
            findLeafMakeSum(node->right, curLevel + 1, deepestLevel, sum);

        if (!node->left && !node->right) {
            if (curLevel > deepestLevel) {
                sum = node->val;
                deepestLevel = curLevel;
            }
            else if (curLevel == deepestLevel)
                sum += node->val;
        }

        return;
    }

    int deepestLeavesSum(TreeNode *root) {
        int deepestLevel = 0;
        int sum = 0;

        findLeafMakeSum(root, 0, deepestLevel, sum);

        return sum;
    }
};