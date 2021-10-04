/* Problem 20. Valid Parentheses
 * https://leetcode.com/submissions/detail/565360094/
 * 1. 문제:
 *   string S가 valid parentheses(정상 중첩)인지 확인하여라.
 *   예를 들어 "{[()()]}"는 parentheses이고, "([)()]"는 아니다.
 *
 * 2. 아이디어:
 *   stack을 활용한다.
 *   open bracket('{', '[', '(')은 stack에 바로 넣고, close bracket('}', ']', ')')은 stack을 pop하면서 자기 짝이 맞는지 확인해본다.
 * */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string::iterator it;

        for (it = s.begin(); it != s.end(); ++it) {
            switch (*it) {
            case '(':
            case '{':
            case '[':
                st.push(*it);
                break;
            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            default:
                return false;
            }
        }

        return (st.empty() ? true : false);
    }
};