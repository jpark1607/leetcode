/* Problem 258. Add Digits
 * https://leetcode.com/submissions/detail/571176629/
 * 1. 문제:
 *   주어진 수를 각 자리마다 더하는 것을 최종 한자리가 나올 때까지 반복하여라.
 *
 * 2. 아이디어:
 *   수행하고 10이 넘으면 다시 수행하는 것을 반복한다.
 * */
class Solution {
public:
    int addDigits(int num) {
        int res = num;

        while (res > 9) {
            num = res;
            res = 0;

            while (num > 0) {
                res += num % 10;
                num /= 10;
            }
        }
        return res;
    }
};