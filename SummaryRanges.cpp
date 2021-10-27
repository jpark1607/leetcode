/* Problem 228. Summary Ranges
 * https://leetcode.com/submissions/detail/578031037/
 * 1. 문제:
 *   주어진 배열에서 연속된 수들은 '->' 표기를 하여 범위로 표기하여라.
 *   예를 들어 [0,2,3,4,6,8,9] 은 ["0","2->4","6","8->9"] 와 같이 표기한다.
 *
 * 2. 아이디어:
 *   한 위치의 인자에서 1씩 커지는 부분을 계속 찾고, 아닌 부분의 직전까지를 화살표 범위로 표기한다.
 * */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        vector<string> res;
        int i = 0;

        while (i < size) {
            string r;
            bool isRange = false;

            r = to_string(nums[i]);

            i++;
            while (i < size && nums[i] == (nums[i - 1] + 1)) {
                isRange = true;
                i++;
            }

            if (isRange) {
                r += "->";
                r += to_string(nums[i - 1]);
            }

            res.push_back(r);
        }

        return res;
    }
};