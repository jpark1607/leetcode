/* Problem 235. Lowest Common Ancestor of a Binary Search Tree
 * https://leetcode.com/submissions/detail/578036198/
 * 1. 문제:
 *   주어진 두 노드의 최소 공통 부모 노드를 찾아라.
 *
 * 2. 아이디어:
 *   어떤 특정 시점의 노드의 값이 주어진 두 노드 중
 *     1. 하나와 같다면 그것을 반환한다.
 *     2. 한 쪽은 크고 한 쪽은 작다면 그것을 반환한다.
 *     3. 둘 다 작다면 left를, 둘 다 크다면 right를 recursive로 찾는다.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val)
            return root;
        else if (root->val > p->val) {
            if (root->val < q->val)
                return root;
            else
                return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val) {
            if (root->val > q->val)
                return root;
            else
                return lowestCommonAncestor(root->right, p, q);
        }

        /* cannot reach */
        return root;
    }
};