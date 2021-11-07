/* Problem 1480. Running Sum of 1d Array
 * https://leetcode.com/submissions/detail/583344491/
 * 1. 문제:
 *   합의 누적을 나타내는 vector를 return 하여라.
 *
 * 2. 아이디어:
 *   X
 * */
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(1, nums[0]);
        int size = nums.size();
        int i;

        for (i = 1; i < size; i++) {
            res.push_back(nums[i] + res[i - 1]);
        }

        return res;
    }
};