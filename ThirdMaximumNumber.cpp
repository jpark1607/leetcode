/* Problem 414. Third Maximum Number
 * https://leetcode.com/submissions/detail/595465394/
 * 1. 문제:
 *   주어진 vector를 distinct하게 정렬한다고 했을 때, 세 번째로 큰 수를 return하여라.
 *   단 distinct sort의 결과가 2개 이하이면, 가장 큰 수를 return한다.
 *
 * 2. 아이디어:
 *   매 index를 돌면서 update한다.
 * */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> v(1, nums[0]);
        int cnt = 1;
        int size = nums.size();
        int i;

        for (i = 0; i < size; i++) {
            if (cnt > 2) {
                if (nums[i] > v[0]) {
                    v.push_back(v[2]);
                    v[2] = v[1];
                    v[1] = v[0];
                    v[0] = nums[i];
                    cnt++;
                }
                else if (nums[i] < v[0] && nums[i] > v[1]) {
                    v.push_back(v[2]);
                    v[2] = v[1];
                    v[1] = nums[i];
                    cnt++;
                }
                else if (nums[i] < v[1] && nums[i] > v[2]) {
                    v.push_back(v[2]);
                    v[2] = nums[i];
                    cnt++;
                }
                else if (nums[i] < v[2]) {
                    v.push_back(nums[i]);
                    cnt++;
                }
            }
            else if (cnt == 2) {
                if (nums[i] > v[0]) {
                    v.push_back(v[1]);
                    v[1] = v[0];
                    v[0] = nums[i];
                    cnt++;
                }
                else if (nums[i] < v[0] && nums[i] > v[1]) {
                    v.push_back(v[1]);
                    v[1] = nums[i];
                    cnt++;
                }
                else if (nums[i] < v[1]) {
                    v.push_back(nums[i]);
                    cnt++;
                }
            }
            else { /* cnt == 1 */
                if (nums[i] > v[0]) {
                    v.push_back(v[0]);
                    v[0] = nums[i];
                    cnt++;
                }
                else if (nums[i] < v[0]) {
                    v.push_back(nums[i]);
                    cnt++;
                }
            }
        }

        if (cnt < 3)
            return v[0];
        else
            return v[2];
    }
};