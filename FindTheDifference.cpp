/* Problem 389. Find the Difference
 * https://leetcode.com/submissions/detail/569265890/
 * 1. 문제:
 *   string t는 s에서 한 글자만 더 넣은 것이다. 어떤 글자가 들어갔는지 출력하여라.
 *
 * 2. 아이디어:
 *   각 글자의 횟수를 담은 vector를 만들고, t를 넣은 뒤 s를 빼는 방식으로 남은 것을 찾는다.
 * */
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> ascii(26, 0);
        int size;
        int i;

        size = t.size();

        for (i = 0; i < size; i++) {
            ascii[t[i] - 'a'] += 1;
        }

        size--;

        for (i = 0; i < size; i++) {
            ascii[s[i] - 'a'] -= 1;
        }

        for (i = 0; i < 26; i++) {
            if (ascii[i] == 1)
                break;
        }

        return i + 'a';
    }
};