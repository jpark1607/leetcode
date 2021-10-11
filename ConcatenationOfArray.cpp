/* Problem 1929. Concatenation of Array
 * https://leetcode.com/submissions/detail/569297799/
 * 1. 문제:
 *   주어진 vector를 두 개 이어 붙인 vector를 return하여라.
 *
 * 2. 아이디어:
 *   .
 * */
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size * 2, 0);
        int i;

        for (i = 0; i < size; i++) {
            res[i] = nums[i];
            res[i + size] = nums[i];
        }

        return res;
    }
};