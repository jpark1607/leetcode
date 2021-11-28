/* Problem 448. Find All Numbers Disappeared in an Array
 * https://leetcode.com/submissions/detail/593932693/
 * 1. 문제:
 *   주어진 vector가 1 ~ n까지의 숫자를 나타낸다고 할 때, 나타나지 않은 숫자들의 집합을 return하여라.
 *
 * 2. 아이디어:
 *   순회하며 빈 것을 찾아 본다.
 * */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        int i;
        vector<bool> chk(size + 1, false);
        vector<int> res;

        for (i = 0; i < size; i++) {
            chk[nums[i]] = true;
        }

        for (i = 1; i <= size; i++) {
            if (!chk[i])
                res.push_back(i);
        }

        return res;
    }
};