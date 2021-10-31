/* Problem 168. Excel Sheet Column Title
 * https://leetcode.com/submissions/detail/579970751/
 * 1. 문제:
 *   엑셀 시트의 n번째 줄을 문자열로 나타내어라.
 *
 * 2. 아이디어:
 *   26으로 나누고 나머지를 구하면 되는데 0일 때가 문제다.
 *   나머지가 0인 경우 26으로 치환하고, 전체에서 1을 빼 준다.
 * */
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        stack<char> tmp;
        int c = 0;
        int i, size;

        while (columnNumber > 0) {
            c = columnNumber % 26;
            if (c == 0)
                c = 26;
            tmp.push(c + 'A' - 1);
            columnNumber /= 26;
            if (c == 26)
                columnNumber--;
        }

        while (!tmp.empty()) {
            res.push_back(tmp.top());
            tmp.pop();
        }

        return res;
    }
};