/* Problem 215. Kth Largest Element in an Array
 * https://leetcode.com/submissions/detail/593388104/
 * 1. 문제:
 *   주어진 배열에서 k번째로 큰 수를 return하여라.
 *
 * 2. 아이디어:
 *   정렬한다.
 * */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();

        sort(nums.begin(), nums.end());

        return nums[size - k];
    }
};