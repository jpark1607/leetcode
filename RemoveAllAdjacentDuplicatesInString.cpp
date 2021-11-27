/* Problem 1047. Remove All Adjacent Duplicates In String
 * https://leetcode.com/submissions/detail/593272743/
 * 1. 문제:
 *   주어진 string에서 중복으로 나온 문자를 제거하는 것을 반복한 결과를 return하여라.
 *
 * 2. 아이디어:
 *   뒤에서부터 탐색하며 stack에 넣으면서 중복이 있으면 뺀다.
 *   stack의 결과를 다시 string에 복사한다.
 * */
class Solution {
public:
    string removeDuplicates(string s) {
        int size = s.size();
        int i;
        string res;
        stack<char> c;

        for (i = size - 1; i >= 0; i--) {
            if (!c.empty() && c.top() == s[i])
                c.pop();
            else
                c.push(s[i]);
        }

        while (!c.empty()) {
            res.push_back(c.top());
            c.pop();
        }

        return res;
    }
};