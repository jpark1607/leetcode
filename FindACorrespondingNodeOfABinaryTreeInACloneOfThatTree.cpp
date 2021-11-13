/* Problem 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 * https://leetcode.com/submissions/detail/586343995/
 * 1. 문제:
 *   original tree와 이를 복제한 cloned tree가 있고, 목표 노드가 있다고 할 때, cloned tree에서 목표 노드와 같은 값의 노드를 return하여라.
 *
 * 2. 아이디어:
 *   둘 다 따라가면 된다.
 *
 * 3. 기타:
 *   이 문제 자체에 두 tree가 필요한 지 의문
 * */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *res = NULL;
        if (original->val == target->val)
            return cloned;

        if (original->left)
            res = getTargetCopy(original->left, cloned->left, target);

        if (res)
            return res;

        if (original->right)
            res = getTargetCopy(original->right, cloned->right, target);

        return res;
    }
};