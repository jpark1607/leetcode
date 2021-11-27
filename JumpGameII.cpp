/* Problem 45. Jump Game II
 * https://leetcode.com/submissions/detail/593317585/
 * 1. 문제:
 *   0번지부터 마지막 번지까지 최소한의 점프 수를 구하여라.
 *
 * 2. 아이디어:
 *   0번지에서 뛸 수 있는 최대 거리를 구한다(last).
 *   cnt를 올리면서 현재 위치를 갱신(cur = last)하고, 다시 cur 위치가 올 때까지 index를 돌며 last의 위치를 새로 갱신한다.
 *   이로 얻을 수 있는 효과는 cur가 last로 갱신되면서 cnt를 올려 주어 해당 위치까지 뛸 수 있는 최소 횟수를 구할 수 있다.
 * */
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int i;
        int cur = 0, last = 0, cnt = 0;

        for (i = 0; i < size - 1; i++) {
            last = max(last, i + nums[i]);

            if (cur == i) {
                cur = last;
                cnt++;
            }
        }

        return cnt;
    }
};