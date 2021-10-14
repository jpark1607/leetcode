/* Problem 350. Intersection of Two Arrays II
 * https://leetcode.com/submissions/detail/571184603/
 * 1. 문제:
 *   두 vector의 교집합 인자들을 반환하여라. (중복 포함)
 *
 * 2. 아이디어:
 *   첫번째 vector를 돌면서 존재하는 인자를 ++ 해주고, 두번째 vector를 돌면서 true를 만나면 -- 해주면서 반환 vector에 넣는다.
 * */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt(1001, 0);
        vector<int> res;
        int i;

        for (i = 0; i < nums1.size(); i++)
            cnt[nums1[i]]++;

        for (i = 0; i < nums2.size(); i++) {
            if (cnt[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                cnt[nums2[i]]--;
            }
        }

        return res;
    }
};