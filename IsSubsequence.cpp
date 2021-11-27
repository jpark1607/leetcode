/* Problem 392. Is Subsequence
 * https://leetcode.com/submissions/detail/593322805/
 * 1. 문제:
 *   string s가 t의 subseqence인지 확인하여라.
 *   subsequence는 t의 일부 문자를 제외하고 s와 같은 경우를 말한다.
 *
 * 2. 아이디어:
 *   앞에서부터 비교한다.
 * */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size1 = s.size(), size2 = t.size();
        int i1 = 0, i2 = 0;

        if (size1 > size2)
            return false;

        while (i1 < size1 && i2 < size2) {
            if (s[i1] == t[i2])
                i1++;
            i2++;
        }

        return (i1 == size1);
    }
};