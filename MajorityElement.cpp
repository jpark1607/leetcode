/* Problem 169. Majority Element
 * https://leetcode.com/submissions/detail/569498235/
 * 1. 문제:
 *   주어진 vector에서 과반을 차지하는 수 하나가 항상 있다고 할 때, 그 수를 구하여라.
 *
 * 2. 아이디어:
 *   루프 돌면서 동일하게 나오는 건 ++, 다른 건 --해보면서 센다. 어차피 과반이 무조건 있으면 cnt가 +로 나오게 되어 있다.
 * */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int num = nums[0], cnt = 1;
        int i;

        for (i = 1; i < size; i++) {
            if (cnt == 0) {
                num = nums[i];
                cnt = 1;
            }
            else {
                if (num == nums[i])
                    cnt++;
                else
                    cnt--;
            }
        }

        return num;
    }
};