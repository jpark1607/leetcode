/* Problem 67. Add Binary
 * https://leetcode.com/submissions/detail/565160751/
 * 1. 문제:
 *   2진수를 표현한 두 string의 합을 2진수 string으로 표현하여라.
 *
 * 2. 아이디어:
 *   뒤에서부터 더한다.
 * */
#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int k = max(i, j) + 1;
        string c(k + 1, 0);
        string res;

        while (k >= 1) {
            if (i >= 0) {
                c[k] += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                c[k] += b[j] - '0';
                j--;
            }

            if (c[k] >= 2) {
                c[k - 1] = 1;
                c[k] -= 2;
            }
            c[k] += '0';
            k--;
        }

        if (c[0] == 1) {
            c[0] += '0';
            res = &(c[0]);
        }
        else
            res = &(c[1]);

        return res;
    }
};