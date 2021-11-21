/* Problem 78. Subsets
 * https://leetcode.com/submissions/detail/590357607/
 * 1. 문제:
 *   주어진 vector의 모든 부분집합(subset)을 구하여라.
 *
 * 2. 아이디어:
 *   0개부터 n개까지의 loop를 돌면서, 개수를 하나씩 (-)하면서 세어 본다.
 *   부분집합의 다음 인자는 마지막으로 참조한 index보다 커야 한다.
 * */
class Solution {
public:
    void subsetCase(vector<int> &nums, vector<vector<int>> &res, vector<int> subs, int n, int k) {
        int i;
        int size = nums.size(), pos = subs.size();

        if (k == 0) {
            res.push_back(subs);
            return;
        }

        subs.push_back(0);
        for (i = n; i < size; i++) {
            subs[pos] = nums[i];
            subsetCase(nums, res, subs, i + 1, k - 1);
        }

        return;
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subs;
        int size = nums.size();
        int i;

        for (i = 0; i <= size; i++)
            subsetCase(nums, res, subs, 0, i);

        return res;
    }
};