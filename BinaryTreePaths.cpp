/* Problem 257. Binary Tree Paths
 * https://leetcode.com/submissions/detail/568224429/
 * 1. 문제:
 *   root부터 각 leaf까지의 모든 경로를 string으로 반환하여라.
 *
 * 2. 아이디어:
 *   따라가면서 출력한다.
 *   ps. itoa, sprintf 왜 안되는지..
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
    string itoa(int num) {
        string s;
        if (num < 0) {
            num *= -1;
            s.push_back('-');
        }

        if (num / 100 > 0) {
            s.push_back((num / 100) + 0x30);
            num %= 100;
            s.push_back((num / 10) + 0x30);
            num %= 10;
            s.push_back(num + 0x30);
        }
        else if (num / 10 > 0) {
            s.push_back((num / 10) + 0x30);
            num %= 10;
            s.push_back(num + 0x30);
        }
        else {
            s.push_back(num + 0x30);
        }

        return s;
    }

    void makePathStr(vector<string> &res, string r, TreeNode *node) {
        r.append(itoa(node->val));

        if (!node->left && !node->right) {
            res.push_back(r);
            return;
        }
        else
            r.append("->");

        if (node->left)
            makePathStr(res, r, node->left);
        if (node->right)
            makePathStr(res, r, node->right);

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string r;

        makePathStr(res, r, root);

        return res;
    }
};