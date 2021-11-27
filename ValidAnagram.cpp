/* Problem 242. Valid Anagram
 * https://leetcode.com/submissions/detail/593390412/
 * 1. 문제:
 *   두 string이 anagram인지 확인하여라.
 *   anagram은 철자마다의 수는 같고 순서만 다른 것이다.
 *
 * 2. 아이디어:
 *   vector를 만들어 철자의 개수를 센다.
 * */
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        int i;

        if (s.size() != t.size())
            return false;

        for (i = 0; i < s.size(); i++)
            cnt[s[i] - 'a']++;

        for (i = 0; i < t.size(); i++) {
            if (cnt[t[i] - 'a'] == 0)
                return false;

            cnt[t[i] - 'a']--;
        }

        return true;
    }
};