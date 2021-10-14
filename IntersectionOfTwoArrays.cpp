/* Problem 349. Intersection of Two Arrays
 * https://leetcode.com/submissions/detail/571182836/
 * 1. 문제:
 *   두 vector의 교집합 인자들을 반환하여라.
 *
 * 2. 아이디어:
 *   첫번째 vector를 돌면서 존재하는 인자를 true로 켜 주고, 두번째 vector를 돌면서 true를 만나면 false로 꺼 주고 반환 vector에 넣는다.
 * */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> cnt(1001, false);
        vector<int> res;
        int i;

        for (i = 0; i < nums1.size(); i++) {
            if (cnt[nums1[i]] == false)
                cnt[nums1[i]] = true;
        }
        for (i = 0; i < nums2.size(); i++) {
            if (cnt[nums2[i]] == true) {
                res.push_back(nums2[i]);
                cnt[nums2[i]] = false;
            }
        }

        return res;
    }
};