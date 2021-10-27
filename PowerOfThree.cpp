/* Problem 326. Power of Three
 * https://leetcode.com/submissions/detail/578043532/
 * 1. 문제:
 *   3의 제곱인지 판단하여라.
 *
 * 2. 아이디어:
 *   3으로 계속 나누어 본다.
 * */
class Solution {
public:
    bool isPowerOfThree(int n) {
        int m;

        if (n <= 0)
            return false;

        while (n > 1) {
            if (n % 3 == 0)
                n /= 3;
            else
                return false;
        }

        return true;
    }
};