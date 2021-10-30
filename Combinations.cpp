/* Problem 77. Combinations
 * https://leetcode.com/submissions/detail/579299115/
 * 1. 문제:
 *   주어진 k개 만큼의 모든 조합의 결과를 구하여라.
 *
 * 2. 아이디어:
 *   recursive
 * */
class Solution {
public:
    void makeCombination(vector<vector<int> > &res, vector<int> com, int last, int cnt, int n, int k) {
        int i;

        if (cnt == k) {
            res.push_back(com);
            return;
        }

        com.push_back(-1);

        for (i = last + 1; i <= n; i++) {
            com[cnt] = i;
            makeCombination(res, com, i, cnt + 1, n, k);
        }

    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> com;

        makeCombination(res, com, 0, 0, n, k);

        return res;
    }
};