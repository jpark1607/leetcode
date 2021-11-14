/* Problem 151. Reverse Words in a String
 * https://leetcode.com/submissions/detail/586902988/
 * 1. 문제:
 *   주어진 string을 단어 단위로 거꾸로 넣은 결과를 return하여라.
 *   단 leading space와 trailing space는 제거하며, 단어 사이에 있는 복수의 space는 한 개의 space로 설정한다.
 *
 * 2. 아이디어:
 *   stack을 이용해서 글자마다 넣다가 space를 만나면 stack의 내용을 string에 복사한다.
 * */
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int size = s.size();
        int i;
        stack<char> st;

        for (i = size - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!st.empty()) {
                    while (!st.empty()) {
                        res.push_back(st.top());
                        st.pop();
                    }
                    res.push_back(' ');
                }
            }
            else
                st.push(s[i]);
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        if (res.back() == ' ') {
            res.resize(res.size() - 1);
        }

        return res;
    }
};