/* Problem 39. Combination Sum
 * https://leetcode.com/submissions/detail/570598006/
 * 1. 문제:
 *   주어진 vector의 인자들의 합이 target이 되는 조합(순열이 아님)의 수를 구하여라.
 *   인자는 복수로 사용 가능하다.
 *
 * 2. 아이디어:
 *   vector를 돌면서 target을 넘어서지 않는 값을 넣는 것을 recursive로 반복한다.
 *   단, vector를 뒤에서부터 탐색하며, 조합을 찾으면 되기 때문에 이전에 넣은 index보다 큰 것은 다시 볼 필요가 없다.
 * */
class Solution {
public:
    void makePartSum(vector<vector<int> > &res, vector<int> &cand, int target, vector<int> list, int idx, int depth) {
        int i;

        for (i = idx; i >= 0; i--) {
            if (cand[i] > target)
                continue;
            else
                break;
        }

        if (i < 0)
            return;

        list.push_back(0);

        for ( ; i >= 0; i--) {
            list[depth] = cand[i];

            if (list[depth] == target) {
                res.push_back(list);
                continue;
            }

            makePartSum(res, cand, target - cand[i], list, i, depth + 1);
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> list;
        int size = candidates.size();

        sort(candidates.begin(), candidates.end());
        makePartSum(res, candidates, target, list, size - 1, 0);

        return res;
    }
};