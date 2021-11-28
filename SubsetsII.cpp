/* Problem 90. Subsets II
 * https://leetcode.com/submissions/detail/593866267/
 * 1. 문제:
 *   주어진 vector의 모든 부분집합(subset)을 구하여라. 단 중복되는 부분집합은 제외한다.
 *
 * 2. 아이디어:
 *   0개부터 n개까지의 loop를 돌면서, 개수를 하나씩 (-)하면서 세어 본다.
 *   부분집합의 다음 인자는 마지막으로 참조한 index보다 커야 한다.
 *   다음 인자가 이전 인자와 값이 같으면 추가하지 않는다.
 * */
class Solution {
public:
    void subsetCase(vector<int> &nums, vector<vector<int>> &res, vector<int> subs, int n, int k) {
        int i;
        int size = nums.size(), pos = subs.size();
        int cur = -99;

        if (k == 0) {
            res.push_back(subs);
            return;
        }

        subs.push_back(0);
        for (i = n; i < size; i++) {
            if (cur == nums[i])
                continue;
            subs[pos] = nums[i];
            subsetCase(nums, res, subs, i + 1, k - 1);
            cur = nums[i];
        }

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subs;
        int size = nums.size();
        int i;

        sort(nums.begin(), nums.end());

        for (i = 0; i <= size; i++)
            subsetCase(nums, res, subs, 0, i);

        return res;
    }
};