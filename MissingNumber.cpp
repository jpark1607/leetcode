/* Problem 268. Missing Number
 * https://leetcode.com/submissions/detail/568207614/
 * 1. 문제:
 *   주어진 vector가 0 ~ n까지의 숫자를 가지고 있을 때, 이 중 빈 숫자를 찾아라.
 *
 * 2. 아이디어:
 *   vector를 돌면서 있는 숫자는 기록용 vector에 true로 바꿔주고, 기록용 vector를 돌면서 false인 것을 반환한다.
 * */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        vector<bool> e(size + 1, false);
        int i;

        for (i = 0; i < size; i++)
            e[nums[i]] = true;

        for (i = 0; i < size + 1; i++) {
            if (e[i] == false)
                return i;
        }

        /* cannot reach */
        return size;
    }
};