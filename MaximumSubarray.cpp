/* Problem 53. Maximum Subarray
 * https://leetcode.com/submissions/detail/570624450/
 * 1. 문제:
 *   주어진 vector에서 합이 최대가 되는 부분합의 결과를 구하여라.
 *
 * 2. 아이디어:
 *   local max와 global max 두 개를 나누어 계산한다.
 *   local max는 i번째 배열값을 더한 것과 그 값 자체를 비교해보는 것으로, i번째 배열값이 더 크면 그 뒤는 더 볼 필요가 없기 때문이다.
 *   global max는 각 지역(?)별로 계산되는 local max와 전체 global max를 비교하기 위함이다.
 * */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int local_max, global_max;
        int i;

        local_max = nums[0];
        global_max = nums[0];

        for (i = 1; i < size; i++) {
            local_max = max(local_max + nums[i], nums[i]);
            global_max = max(local_max, global_max);
        }

        return global_max;
    }
};