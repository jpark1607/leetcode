/* Problem 173. Binary Search Tree Iterator
 * https://leetcode.com/submissions/detail/593236961/
 * 1. 문제:
 *   주어진 tree를 중위 순회하는 class를 만들어라.
 *
 * 2. 아이디어:
 *   stack을 이용해서 오른쪽 -> 노드 -> 왼쪽의 순서대로 탐색하여 넣고, 이를 next로 뽑는다.
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
class BSTIterator {
private:
    stack<int> st;
public:
    void inputStack(TreeNode *node, stack<int> &s) {
        if (!node)
            return;

        if (node->right)
            inputStack(node->right, s);

        st.push(node->val);

        if (node->left)
            inputStack(node->left, s);

        return;
    }

    BSTIterator(TreeNode* root) {
        inputStack(root, st);
    }

    int next() {
        int n = st.top();
        st.pop();
        return n;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */