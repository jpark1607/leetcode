/* Problem 88. Merge Sorted Array
 * https://leetcode.com/submissions/detail/565550792/
 * 1. 문제:
 *   오름차순으로 정렬된 vector num1과 num2를 num1의 공간에 merge하여라.
 *
 * 2. 아이디어:
 *   뒤에서부터 큰 순서대로 붙인다.
 * */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        m--;
        n--;

        while (i >= 0) {
            if (m >= 0 && n >= 0 && nums1[m] >= nums2[n]) {
                nums1[i] = nums1[m];
                m--;
                i--;
            }
            if (m >= 0 && n >= 0 && nums1[m] < nums2[n]) {
                nums1[i] = nums2[n];
                n--;
                i--;

            }

            if (m < 0) {
                while (n >= 0) {
                    nums1[i] = nums2[n];
                    n--;
                    i--;
                }
            }
            if (n < 0) {
                while (m >= 0) {
                    nums1[i] = nums1[m];
                    m--;
                    i--;
                }
            }
        }
    }
};