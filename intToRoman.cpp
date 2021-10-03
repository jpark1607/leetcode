/* Problem 12. Integer to Roman
 * https://leetcode.com/submissions/detail/565026569/
 * 1. 문제:
 *   주어진 수를 로마 표기로 바꾸어라.
 *
 * 2. 아이디어:
 *   그냥 큰 수부터 나누어 본다.
 * */

class Solution {
public:
    string intToRoman(int num) {
        string res;

        while (num > 0) {
            if (num / 1000 > 0) {
                res.push_back('M');
                num -= 1000;
            }
            else if (num / 900 > 0) {
                res.push_back('C');
                res.push_back('M');
                num -= 900;
            }
            else if (num / 500 > 0) {
                res.push_back('D');
                num -= 500;
            }
            else if (num / 400 > 0) {
                res.push_back('C');
                res.push_back('D');
                num -= 400;
            }
            else if (num / 100 > 0) {
                res.push_back('C');
                num -= 100;
            }
            else if (num / 90 > 0) {
                res.push_back('X');
                res.push_back('C');
                num -= 90;
            }
            else if (num / 50 > 0) {
                res.push_back('L');
                num -= 50;
            }
            else if (num / 40 > 0) {
                res.push_back('X');
                res.push_back('L');
                num -= 40;
            }
            else if (num / 10 > 0) {
                res.push_back('X');
                num -= 10;
            }
            else if (num / 9 > 0) {
                res.push_back('I');
                res.push_back('X');
                num -= 9;
            }
            else if (num / 5 > 0) {
                res.push_back('V');
                num -= 5;
            }
            else if (num / 4 > 0) {
                res.push_back('I');
                res.push_back('V');
                num -= 4;
            }
            else {
                res.push_back('I');
                num -= 1;
            }
        }

        return res;
    }
};