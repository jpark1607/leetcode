/* Problem 219. Contains Duplicate II
 * https://leetcode.com/submissions/detail/594978717/
 * 1. 문제:
 *   주어진 vector에서 중복되는 수의 위치의 차이가 k를 넘지 않는지 확인하여라.
 *
 * 2. 아이디어:
 *   값을 key로 가지고, index를 value로 가지는 hash map을 사용한다.
 * */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int size = nums.size();
        int i;

        for (i = 0; i < size; i++) {
            unordered_map<int, int>::iterator it = um.find(nums[i]);
            if (it != um.end() && i - it->second <= k)
                return true;
            else
                um[nums[i]] = i;
        }

        return false;
    }
};