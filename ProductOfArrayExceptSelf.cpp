/* Problem 238. Product of Array Except Self
 * https://leetcode.com/submissions/detail/595480855/
 * 1. 문제:
 *   주어진 vector에서 특정 index에 대하여 그 index의 value를 제외한 나머지 값들의 곱을 모두 return하여라.
 *
 * 2. 아이디어:
 *   vector 전체에 대하여 앞에서부터 곱한 값들의 누적과 뒤에서부터 곱한 값들의 누적을 담은 vector를 각각 만든다.
 *   특정 index에서의 결과는, 앞에서부터 index - 1까지 곱한 값에 뒤에서부터 index + 1까지 곱한 값을 곱하면 된다.
 * */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> pref(size, 0);
        vector<int> postf(size, 0);
        vector<int> res(size, 0);
        int i;

        pref[0] = nums[0];
        for (i = 1; i < size; i++)
            pref[i] = pref[i - 1] * nums[i];

        postf[size - 1] = nums[size - 1];
        for (i = size - 2; i >= 0; i--)
            postf[i] = postf[i + 1] * nums[i];

        res[0] = postf[1];
        res[size - 1] = pref[size - 2];

        for (i = 1; i < size - 1; i++) {
            res[i] = pref[i - 1] * postf[i + 1];
        }

        return res;
    }
};