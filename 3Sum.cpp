/* Problem 15. 3Sum
 * https://leetcode.com/submissions/detail/593422205/
 * 1. 문제:
 *   세 수의 합이 0이 되는 경우를 모두 찾아라.
 *   (단 중복은 제외한다)
 *
 * 2. 아이디어:
 *   아래 케이스를 각각 구한다.
 *   case #1: 0 0 0일 때
 *   case #2: 0, 음수, 양수 일 때
 *   case #3: 음수, 음수, 양수 일 때
 *   case #4: 양수, 음수, 양수 일 때
 * */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> zero(3, 0);
        int pivot, left, right;
        int i, size = nums.size(), cnt = 0;

        if (size < 3)
            return res;

        sort(nums.begin(), nums.end());

        if (nums[0] > 0 || nums[size - 1] < 0)
            return res;

        for (i = 0; i < size; i++) {
            if (nums[i] == 0)
                cnt++;
        }

        if (cnt > 0) {
            /* case #1: 0,0,0 */
            if (cnt >= 3)
                res.push_back(zero);

            /* case #2: pivot = 0 */
            left = 0;
            right = size - 1;

            while (nums[left] < 0 && nums[right] > 0) {
                if (nums[left] + nums[right] == 0) {
                    zero[1] = nums[left];
                    zero[2] = nums[right];
                    res.push_back(zero);

                    do {
                        left++;
                    } while (zero[1] == nums[left]);
                    do {
                        right--;
                    } while (zero[2] == nums[right]);
                }
                else if (nums[left] + nums[right] > 0)
                    right--;
                else if (nums[left] + nums[right] < 0)
                    left++;
            }
        }

        /* case #3: pivot < 0 */
        zero[0] = 0;
        for (pivot = 0; nums[pivot] < 0; pivot++) {
            if (zero[0] == nums[pivot])
                continue;
            left = pivot + 1;
            right = size - 1;

            zero[0] = nums[pivot];
            zero[1] = 0;
            zero[2] = 0;

            while (nums[left] < 0 && nums[right] > 0) {
                if (nums[pivot] + nums[left] + nums[right] == 0) {
                    zero[1] = nums[left];
                    zero[2] = nums[right];
                    res.push_back(zero);

                    do {
                        left++;
                    } while (zero[1] == nums[left]);
                    do {
                        right--;
                    } while (zero[2] == nums[right]);
                }
                else if (nums[pivot] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[pivot] + nums[left] + nums[right] < 0)
                    left++;
            }
        }

        /* case #4: pivot > 0 */
        zero[0] = 0;
        for (pivot = size - 1; nums[pivot] > 0; pivot--) {
            if (zero[0] == nums[pivot])
                continue;
            left = 0;
            right = pivot - 1;

            zero[0] = nums[pivot];
            zero[1] = 0;
            zero[2] = 0;

            while (nums[left] < 0 && nums[right] > 0) {
                if (nums[pivot] + nums[left] + nums[right] == 0) {
                    zero[1] = nums[left];
                    zero[2] = nums[right];
                    res.push_back(zero);

                    do {
                        left++;
                    } while (zero[1] == nums[left]);
                    do {
                        right--;
                    } while (zero[2] == nums[right]);
                }
                else if (nums[pivot] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[pivot] + nums[left] + nums[right] < 0)
                    left++;
            }
        }

        return res;
    }
};