/* Problem 415. Add Strings
 * https://leetcode.com/submissions/detail/571955897/
 * 1. 문제:
 *   두 string을 수로 인식하여 더한 결과를 출력하여라.
 *
 * 2. 아이디어:
 *   뒤에서부터 더하면서 stack에 넣고, 마지막에 stack에서 빼면서 string에 넣어 준다.
 * */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        stack<char> st;
        int i = num1.size() - 1, j = num2.size() - 1;
        int up = 0;

        while (i >= 0 && j >= 0) {
            up += (num1[i] - '0') + (num2[j] - '0');
            st.push((up % 10) + '0');
            up /= 10;
            i--;
            j--;
        }

        while (i >= 0) {
            up += num1[i] - '0';
            st.push((up % 10) + '0');
            up /= 10;
            i--;
        }

        while (j >= 0) {
            up += num2[j] - '0';
            st.push((up % 10) + '0');
            up /= 10;
            j--;
        }

        if (up == 1)
            res.push_back('1');

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};