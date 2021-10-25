/* Problem 263. Ugly Number
 * https://leetcode.com/submissions/detail/576973612/
 * 1. 문제:
 *   주어진 수가 2, 3, 5로만 나누어 1이 되면 true, 그렇지 않으면 false를 반환하여라.
 *
 * 2. 아이디어:
 *   각 수를 돌려본다.
 * */
class Solution {
public:
    bool isUgly(int n) {
        if (n < 1)
            return false;

        while (n % 2 == 0)
            n /= 2;

        while (n % 3 == 0)
            n /= 3;

        while (n % 5 == 0)
            n /= 5;

        return (n == 1) ? true : false;
    }
};