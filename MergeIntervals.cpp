/* Problem 56. Merge Intervals
 * https://leetcode.com/submissions/detail/586815113/
 * 1. 문제:
 *   주어진 vector가 각 interval을 표현할 때, 교차하는 interval들을 merge한 vector를 return하여라.
 *
 * 2. 아이디어:
 *   정렬하고 앞에서부터 체크한다.
 * */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<int> tmp(2, 0);
        int size = intervals.size();
        int s, e;
        int i;

        sort(intervals.begin(), intervals.end());

        tmp = intervals[0];

        if (size == 1) {
            res.push_back(tmp);
            return res;
        }

        for (i = 1; i < size - 1; i++) {
            if (intervals[i][0] >= tmp[0] && intervals[i][0] <= tmp[1])
                tmp[1] = max(intervals[i][1], tmp[1]);
            else {
                res.push_back(tmp);
                tmp = intervals[i];
            }
        }

        if (intervals[i][0] >= tmp[0] && intervals[i][0] <= tmp[1]) {
            tmp[1] = max(intervals[i][1], tmp[1]);
            res.push_back(tmp);
        }
        else {
            res.push_back(tmp);
            res.push_back(intervals[i]);
        }

        return res;
    }
};