/* Problem 405. Convert a Number to Hexadecimal
 * https://leetcode.com/submissions/detail/595460722/
 * 1. 문제:
 *   주어진 10진수를 hex 값으로 변환하여라.
 *
 * 2. 아이디어:
 *   unsigned int에 넣은 뒤 16으로 나눈 나머지를 반복해서 가져온다.
 * */
class Solution {
public:
    string toHex(int num) {
        uint32_t unum = num, buf;
        string res;
        stack<char> s;

        if (num == 0) {
            res.push_back('0');
            return res;
        }

        while (unum > 0) {
            buf = unum % 16;
            switch (buf) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    s.push(buf + '0');
                    break;
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                    s.push(buf - 10 + 'a');
                    break;
            }
            unum /= 16;
        }

        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};