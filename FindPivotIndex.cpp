/* Problem 724. Find Pivot Index
 * https://leetcode.com/submissions/detail/592056455/
 * 1. 문제:
 *   특정 index를 기점으로 왼쪽과 오른쪽의 합이 같은 index를 찾아라. 없으면 -1
 *
 * 2. 아이디어:
 *   index가 0일 때 right의 모든 합을 구하고, 그 뒤로 left에는 더해주고 right는 빼 주면서 비교해본다.
 * */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, size = nums.size();
        int left = 0, right = 0;

        for (i = 1; i < size; i++)
            right += nums[i];

        if (left == right)
            return 0;

        for (i = 1; i < size; i++) {
            left += nums[i - 1];
            right -= nums[i];

            if (left == right)
                return i;
        }

        return -1;
    }
};