/* Problem 342. Power of Four
 * https://leetcode.com/submissions/detail/578042818/
 * 1. 문제:
 *   4의 제곱인지 판단하여라.
 *
 * 2. 아이디어:
 *   4로 계속 나누어 본다.
 * */
class Solution {
public:
    bool isPowerOfFour(int n) {
        int m;

        if (n <= 0)
            return false;

        while (n > 1) {
            if (n % 4 == 0)
                n /= 4;
            else
                return false;
        }

        return true;
    }
};