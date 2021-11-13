/* Problem 1008. Construct Binary Search Tree from Preorder Traversal
 * https://leetcode.com/submissions/detail/586374764/
 * 1. 문제:
 *   주어진 vector가 preorder BST를 보여준다고 할 때, 이를 tree로 만들어 return하여라.
 *
 * 2. 아이디어:
 *   매 값을 루트부터 따라가본다.
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]), *node = NULL;
        int size = preorder.size();
        int i;

        for (i = 1; i < size; i++) {
            node = root;

            while (1) {
                if (preorder[i] < node->val) {
                    if (node->left)
                        node = node->left;
                    else {
                        node->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
                else {
                    if (node->right)
                        node = node->right;
                    else {
                        node->right = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }

        return root;
    }
};