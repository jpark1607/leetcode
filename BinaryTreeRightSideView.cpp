/* Problem 199. Binary Tree Right Side View
 * https://leetcode.com/submissions/detail/576287979/
 * 1. 문제:
 *   주어진 tree를 오른쪽에서 바라본다고 가정했을 때, 보이는 숫자들을 상위 레벨부터 출력하여라.
 *
 * 2. 아이디어:
 *   right, left를 순서대로 따라가면서, 현재 level보다 cnt(확인된 노드의 수)가 적으면 그 노드의 것이 아직 저장 안 된 것이므로 저장한다.
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
    void searchChildren(vector<int> &res, int &cnt, int level, TreeNode *node) {
        if (level > cnt) {
            res.push_back(node->val);
            cnt++;
        }

        if (node->right)
            searchChildren(res, cnt, level + 1, node->right);
        if (node->left)
            searchChildren(res, cnt, level + 1, node->left);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        TreeNode *node = root;
        int cnt = 0;

        if (root)
            searchChildren(res, cnt, 1, root);

        return res;
    }
};