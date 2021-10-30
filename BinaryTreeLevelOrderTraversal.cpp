/* Problem 102. Binary Tree Level Order Traversal
 * https://leetcode.com/submissions/detail/579330772/
 * 1. 문제:
 *   주어진 tree를 level 별로 vector로 모으고(vector 내에서는 왼쪽부터 오른쪽으로), 그 vector들을 모은 vector를 return하여라.
 *
 * 2. 아이디어:
 *   최종 vector의 개수가 level의 수와 같기 때문에 이를 유지할 수 있는 변수(cnt)가 필요하다.
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
    void insertValue(TreeNode *node, vector<vector<int> > &res, int &cnt, int lvl) {
        if (lvl > cnt) {
            vector<int> v;
            res.push_back(v);
            cnt++;
        }

        res[lvl].push_back(node->val);

        if (node->left) {
            insertValue(node->left, res, cnt, lvl + 1);
        }
        if (node->right) {
            insertValue(node->right, res, cnt, lvl + 1);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        int cnt = -1;

        if (root)
            insertValue(root, res, cnt, 0);

        return res;
    }
};