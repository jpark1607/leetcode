/* Problem 80. Remove Duplicates from Sorted Array II
 * https://leetcode.com/submissions/detail/586857570/
 * 1. 문제:
 *   주어진 non-decrease ordered sort vector에서, 특정 숫자가 세 번 이상 반복되지 않도록 제거한 결과를 return하여라.
 *
 * 2. 아이디어:
 *   주어진 vector 전체를 순회하는 index(i)와 반복을 제외한 index(p)를 두어 복사해간다.
 * */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int total = nums.size();
        int size = nums.size();
        int i;
        int p = 1;
        bool conflict = false;

        for (i = 1; i < size; i++) {
            if (nums[i] == nums[i - 1]) {
                if (!conflict) {
                    conflict = true;
                    nums[p] = nums[i];
                    p++;
                }
                else {
                    total--;
                    continue;
                }
            }
            else {
                conflict = false;
                nums[p] = nums[i];
                p++;
            }
        }

        return total;
    }
};