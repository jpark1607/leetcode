/* Problem 13. Roman to Integer
 * https://leetcode.com/submissions/detail/565029660/
 * 1. 문제:
 *   주어진 로마 표기법을 정수로 바꾸어라.
 *
 * 2. 아이디어:
 *   문자열에 맞는 수로 치환하되, I, X, C의 경우 뒤까지 비교해본다.
 * */
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int size = s.size();
        int i = 0;

        for (i = 0; i < size; i++) {
            if (s[i] == 'I') {
                if (i + 1 < size && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    res -= 1;
                else
                    res += 1;
            }
            else if (s[i] == 'V') {
                res += 5;
            }
            else if (s[i] == 'X') {
                if (i + 1 < size && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    res -= 10;
                else
                    res += 10;
            }
            else if (s[i] == 'L') {
                res += 50;
            }
            else if (s[i] == 'C') {
                if (i + 1 < size && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    res -= 100;
                else
                    res += 100;
            }
            else if (s[i] == 'D') {
                res += 500;
            }
            else if (s[i] == 'M') {
                res += 1000;
            }
        }

        return res;
    }
};