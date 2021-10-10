/* Problem 231. Power of Two
 * https://leetcode.com/submissions/detail/568810604/
 * 1. 문제:
 *   2의 거듭제곱인지 구하여라.
 *
 * 2. 아이디어:
 *   2의 거듭제곱은 2진법 표기 시 1이 마지막 한 번만 나와야 한다.
 *   (16 = 10000, 4 = 100, ...)
 * */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        while (n > 1) {
            if (n % 2 == 1)
                return false;
            n /= 2;
        }

        return true;
    }
};