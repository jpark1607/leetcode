/* Problem 283. Move Zeroes
 * https://leetcode.com/submissions/detail/576976355/
 * 1. 문제:
 *   주어진 배열에서 0을 모두 뒤로 미루어 재정렬하여라.
 *
 * 2. 아이디어:
 *   배열의 모든 index를 탐색하면서 다음 넣는 위치를 가리키는 포인터를 두어 복사한다.
 * */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        int i = 0, j = 0;

        for (i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        for ( ; j < size; j++) {
            nums[j] = 0;
        }

        return;
    }
};