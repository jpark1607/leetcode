/* Problem 75. Sort Colors
 * https://leetcode.com/submissions/detail/586833771/
 * 1. 문제:
 *   주어진 vector에서 0, 1, 2가 각각의 색을 나타낸다고 할 때, 0부터 정렬하여라. (sort 함수 사용 금지)
 *
 * 2. 아이디어:
 *   vector를 한바퀴 돌면서 0을 왼쪽에 모두 위치시키고, 다시 거꾸로 돌면서 2를 오른쪽에 위치시킨다.
 *   이 과정에서 1은 모두 중앙에 자동 정렬된다.
 * */
class Solution {
public:
    void swap(int &num1, int &num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
        return;
    }

    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int pos1 = 0, pos2 = size - 1;
        int tmp;
        int i;

        for (i = pos1; i < size; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[pos1]);
                pos1++;
            }
        }

        for (i = pos2; i >= pos1; i--) {
            if (nums[i] == 2) {
                swap(nums[i], nums[pos2]);
                pos2--;
            }
        }

        return;
    }
};