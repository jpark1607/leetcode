/* Problem 217. Contains Duplicate
 * https://leetcode.com/submissions/detail/568205887/
 * 1. 문제:
 *   주어진 vector 내에 중복 값이 있을 경우 true, 없으면 false를 반환하여라.
 *
 * 2. 아이디어:
 *   정렬한다.
 * */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        int i;

        if (size == 1)
            return false;

        sort(nums.begin(), nums.end());

        for (i = 0; i < size - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }

        return false;
    }
};