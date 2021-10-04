/* Problem 100. Same Tree
 * https://leetcode.com/submissions/detail/565647185/
 * 1. 문제:
 *   주어진 두 tree가 (모양과 값 모두) 똑같은지 판단하여라.
 *
 * 2. 아이디어:
 *   다음의 경우는 모두 다른 것이다.
 *   2-1. p가 NULL이고 q가 NULL이 아니거나, 그 반대으 ㅣ경우
 *   2-2. p의 값과 q의 값이 다른 경우
 *   2-3. 위 2-1과 2-2를 left, right 각각에 대해서 적용
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if ((p && !q) || (q && !p))
            return false;
        if (p->val != q->val)
            return false;
        if (!isSameTree(p->left, q->left))
            return false;
        if (!isSameTree(p->right, q->right))
            return false;
        return true;
    }
};