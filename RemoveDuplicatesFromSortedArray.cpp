/* Problem 26. Remove Duplicates from Sorted Array
 * https://leetcode.com/submissions/detail/565115657/
 * 1. 문제:
 *   오름차순으로 정렬된 vector가 있을 때, 중복을 제거하여 앞에서부터 쌓이도록 하고, distinct 개수를 구하여라.
 *
 * 2. 아이디어:
 *   특정 위치(l)부터 중복된 것을 모두 건너뛰고, 그 다음 인자(r)를 l의 다음 위치에 넣어주는 것을 반복한다.
 *   vector의 마지막에 중복된 것을이 있으면 vector 범위를 초과해서 읽는 문제가 있는데, 예외처리보다는 nums에 안 들어갈 숫자를 넣는 방식으로
 *   우회했다.
 * */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int l = 0, r = 1;

        if (size < 2)
            return size;

        nums.push_back(999);

        while (r < size) {
            while (nums[r] == nums[l]) {
                r++;
            }
            l++;
            nums[l] = nums[r];
        }

        return l;
    }
};