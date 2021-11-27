/* Problem 1021. Remove Outermost Parentheses
 * https://leetcode.com/submissions/detail/593270517/
 * 1. 문제:
 *   주어진 parentheses에서 가장 바깥쪽 묶음을 제외하고 나머지를 return하여라.
 *
 * 2. 아이디어:
 *   stack을 써서 empty가 아닐 때에만 복사한다.
 * */
class Solution {
public:
    string removeOuterParentheses(string s) {
        int size = s.size();
        int i;
        stack<char> c;
        string res;

        for (i = 0; i < size; i++) {
             switch (s[i]) {
                 case '(':
                     if (!c.empty())
                         res.push_back('(');
                     c.push('(');
                     break;
                 case ')':
                     c.pop();
                     if (!c.empty())
                         res.push_back(')');
                     break;
             }
        }

        return res;
    }
};