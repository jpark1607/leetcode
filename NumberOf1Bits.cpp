/* Problem 191. Number of 1 Bits
 * https://leetcode.com/submissions/detail/569504155/
 * 1. 문제:
 *   주어진 수에 포함된 bit 1의 개수를 출력하시오.
 *
 * 2. 아이디어:
 *   2로 계속 나누어 본다.
 * */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        while (n > 0) {
            if (n % 2 == 1)
                cnt++;
            n /= 2;
        }

        return cnt;
    }
};