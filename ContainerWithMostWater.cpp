/* Problem 11. Container With Most Water
 * https://leetcode.com/submissions/detail/575355682/
 * 1. 문제:
 *   각 좌표마다 기둥이 있을 때, 이 중 두 개를 골라 물을 채운다고 가정하면 최대로 채울 수 있는 물의 양을 구하여라.
 *
 * 2. 아이디어:
 *   양쪽에서 길이가 긴 것을 놔두면서 계속 계산해본다(greedy algorithm).
 * */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int s = 0, e = height.size() - 1;

        while (s < e) {
            res = max(res, min(height[s], height[e]) * (e - s));

            if (height[s] > height[e])
                e--;
            else
                s++;
        }
        return res;
    }
};