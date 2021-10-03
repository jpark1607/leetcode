/* Problem 1. Two Sum
 * https://leetcode.com/submissions/detail/564570016/
 * 1. 문제:
 *   vector nums 안에 인자들 중, 두 개의 합이 target이 되는 index들을 return하라.
 *
 * 2. 아이디어:
 *   그냥 찾으면 n의 제곱만큼 돌게 되므로, 정렬해서 값 자체를 찾은 뒤 값을 토대로 원본 vector에서 index를 찾는다.
 * */
#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res, tmp;
        int n1, n2;
        int i;

        tmp.assign(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());

        n1 = 0;
        n2 = size - 1;
        while (n1 <= n2) {
            if (tmp[n1] + tmp[n2] < target)
                n1++;
            else if (tmp[n1] + tmp[n2] > target)
                n2--;
            else {
                n1 = tmp[n1];
                n2 = tmp[n2];
                break;
            }
        }

        for (i = 0; i < size; i++) {
            if (nums[i] == n1 || nums[i] == n2) {
                res.push_back(i);
            }

            if (res.size() == 2)
                return res;
        }
        return res;
    }
};