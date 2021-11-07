/* Problem 1920. Build Array from Permutation
 * https://leetcode.com/submissions/detail/583343430/
 * 1. 문제:
 *   nums[i] 값을 index로 하는 nums[nums[i]]를 순서대로 return하여라.
 *
 * 2. 아이디어:
 *   X
 * */
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        int i;

        for (i = 0; i < size; i++) {
            res.push_back(nums[nums[i]]);
        }

        return res;
    }
};