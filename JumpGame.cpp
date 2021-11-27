/* Problem 55. Jump Game
 * https://leetcode.com/submissions/detail/593309866/
 * 1. 문제:
 *   각 vector의 인자가 그 index에서 최대 뛸 수 있는 거리라 할 때, index 0번지부터 마지막 index 번지까지 뛰어서 넘어 갈 수 있는지 찾아라.
 *
 * 2. 아이디어:
 *   인자가 0이 있는 경우, 그 0을 뛰어넘을 수 있는지 확인한다.
 * */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int i;
        int hole = -1;


        for (i = size - 2; i >= 0; i--) {
            if (nums[i] == 0 && hole == -1)
                hole = i;
            else if (hole != -1) {
                if (nums[i] + i > hole)
                    hole = -1;
            }
        }

        return (hole == -1) ? true : false;
    }
};