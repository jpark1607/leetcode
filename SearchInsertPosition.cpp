/* Problem 35. Search Insert Position
 * https://leetcode.com/submissions/detail/565138481/
 * 1. 문제:
 *   특정 수 target이 정렬된 vector nums에서 들어갈 위치를 찾아라.
 *
 * 2. 아이디어:
 *   binary search
 * */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size, m = (l + r) / 2;

        if (nums[0] > target)
            return 0;
        else if (nums[size - 1] < target) {
            return size;
        }

        while (l <= r) {
            m = (l + r) / 2;

            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }

        if (nums[m] < target)
            m++;

        return m;
    }
};