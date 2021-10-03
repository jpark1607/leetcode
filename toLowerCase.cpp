/* Problem 709. To Lower Case
 * https://leetcode.com/submissions/detail/565039807/
 * 1. 문제:
 *   대문자롤 소문자로 치환하여라.
 *
 * 2. 아이디어:
 *   대문자에 0x20을 더해주면 된다.
 * */
class Solution {
public:
    string toLowerCase(string s) {
        int size = s.size();
        string res;
        int i;

        for (i = 0; i < size; i++) {
            res.push_back(s[i]);
            if (s[i] >= 'A' && s[i] <= 'Z')
                res[i] += 0x20;
        }

        return res;
    }
};