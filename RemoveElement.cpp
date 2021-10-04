/* Problem 27. Remove Element
 * https://leetcode.com/submissions/detail/565131838/
 * 1. 문제:
 *   vector nums에서 val을 제외한 나머지를 앞으로 정렬하여 return하여라.
 *
 * 2. 아이디어:
 *   r로 vector를 따라가면서, 중복이 있을 경우 l의 위치를 유지시킨다.
 *   r의 위치에서 중복이 안 나올 때 l의 위치에 덮어씌운다.
 *   중복이 나올 경우는 전체 개수(size)에서 1씩 빼 준다.
 * */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int res = size;
        int l = 0, r = 0;

        for ( ; r < size; r++) {
            if (nums[r] != val) {
                nums[l] = nums[r];
                l++;
            }
            else
                res--;
        }

        return res;
    }
};