/* Problem 136. Single Number
 * https://leetcode.com/submissions/detail/586896788/
 * 1. 문제:
 *   주어진 vector에서 모든 인자가 2개씩 있고, 하나의 인자만 1개가 있다고 할 때, 그 인자의 값을 구하여라.
 *
 * 2. 아이디어:
 *   XOR
 * */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int size = nums.size();
        int i;

        for (i = 0; i < size; i++) {
            res ^= nums[i];
        }

        return res;
    }
};