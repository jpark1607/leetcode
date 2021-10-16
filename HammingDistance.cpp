/* Problem 461. Hamming Distance
 * https://leetcode.com/submissions/detail/571970127/
 * 1. 문제:
 *   두 수에서 서로 bit값이 다른 자리의 수를 구하여라.
 *
 * 2. 아이디어:
 *   XOR
 * */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x ^ y, cnt = 0;

        while (res > 0) {
            cnt += res % 2;
            res /= 2;
        }

        return cnt;
    }
};