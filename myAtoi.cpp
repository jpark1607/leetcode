#include <cstdlib>
#ifndef _WIN32
#include <bits/stdc++.h>
#else
#include <limits>
#endif /* _WIN32 */

/* Problem 8. String to Integer
 * https://leetcode.com/submissions/detail/565002822/
 * 1. 문제:
 *   주어진 string을 int로 바꾸어라.
 *   단 변경 도중 int의 범위보다 커질 경우, 음수는 INT_MIN, 양수는 INT_MAX를 return한다.
 *
 * 2. 아이디어:
 *   leading whitespace 넘어가고, '+'와 '-'를 먼저 처리하여 부호를 인식해 놓는다.
 *   하나씩 자리를 보면서 '0'에서 '9' 범위 안에 있는지 확인한다.
 *   주의해야 할 것은 int 범위를 넘어가는 것에 대한 처리인데, 양수 기준으로는 특정 시점까지의 result가 다음과 같은지 확인한다.
 *   2-1. 10배를 했을 경우 INT_MAX보다 커지는 지
 *   2-2. 10배를 했을 경우 INT_MAX와 같을 때, 마지막 자리가 7보다 큰 지
 *   음수는 반대로 한다.
 * */
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int res = 0, num;
        int sign = 1;
        int i = 0;

        if (size == 0)
            return 0;

        while (s[i] == ' ')
            i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;

        for ( ; i < size; i++) {
            if (!(s[i] >= '0' && s[i] <= '9'))
                break;

            num = (s[i] - 48) * sign;

            if (sign == -1) {
                if ((INT_MIN / 10 > res) || ((INT_MIN / 10 == res) && (INT_MIN % 10 > num)))
                    return INT_MIN;
                else
                    res = res * 10 + num;
            }
            else {
                if ((INT_MAX / 10 < res) || ((INT_MAX / 10 == res) && (INT_MAX % 10 < num)))
                    return INT_MAX;
                else
                    res = res * 10 + num;
            }
        }

        return res;
    }
};