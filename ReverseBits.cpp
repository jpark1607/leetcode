/* Problem 190. Reverse Bits
 * https://leetcode.com/submissions/detail/569508165/
 * 1. 문제:
 *   주어진 수 n의 bit를 거꾸로 한 수를 출력하라.
 *
 * 2. 아이디어:
 *   주어진 수 n을 오른쪽 shift하면서 마지막 자리의 bit만 확인하고, 새로운 수를 왼쪽 shift하면서 그 값을 넣어 준다.
 * */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        int num;
        uint32_t res = 0;

        while (i < 32) {
            num = n & 0x1;
            n = n >> 1;
            res = res << 1;
            res += num;
            i++;
        }

        return res;
    }
};