/* Problem 1672. Richest Customer Wealth
 * https://leetcode.com/submissions/detail/583347546/
 * 1. 문제:
 *   주어진 이차원 vector에서 각 row가 사람의 재산이라고 할 때, 제일 많은 재산을 return하여라.
 *
 * 2. 아이디어:
 *   X
 * */
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int size1 = accounts.size(), size2 = accounts[0].size();
        int i, j;
        int cur = 0, res = 0;

        for (i = 0; i < size1; i++) {
            cur = 0;
            for (j = 0; j < size2; j++) {
                cur += accounts[i][j];
            }
            res = max(cur, res);
        }

        return res;
    }
};