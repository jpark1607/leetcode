/* Problem 7. Reverse Integer
 * https://leetcode.com/submissions/detail/566242560/
 * 1. 문제:
 *   주어진 수의 앞뒤를 뒤바꾸어 return하여라.
 *
 * 2. 아이디어:
 *   나머지 구하는 것을 반복한다.
 * */
class Solution {
public:
    int reverse(int x) {
        int res = 0, num = 0, sign = 1;

        if (x == 0)
            return x;

        if (x < 0)
            sign = -1;

        res = x % 10;
        x /= 10;
        x *= sign;

        while (x > 0) {
            num = (x % 10) * sign;
            x /= 10;

            if (sign == -1) {
                if ((INT_MIN / 10 > res) || ((INT_MIN / 10 == res) && (INT_MIN % 10 > num)))
                    return 0;
                else
                    res = res * 10 + num;
            }
            else {
                if ((INT_MAX / 10 < res) || ((INT_MAX / 10 == res) && (INT_MAX % 10 < num)))
                    return 0;
                else
                    res = res * 10 + num;
            }
        }

        return res;
    }
};