/* Problem 171. Excel Sheet Column Number
 * https://leetcode.com/submissions/detail/569500994/
 * 1. 문제:
 *   엑셀 시트의 열을 나타내는 문자가 몇번째 줄인지 출력하라.
 *
 * 2. 아이디어:
 *   앞에서부터 읽으면서 더하고, 곱하기 26 한다.
 * */
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();
        int i;
        int n = 0;

        for (i = 0; i < size; i++) {
            n *= 26;
            n += columnTitle[i] - 'A' + 1;
        }

        return n;
    }
};