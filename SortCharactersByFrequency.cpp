/* Problem 451. Sort Characters By Frequency
 * https://leetcode.com/problems/sort-characters-by-frequency/submissions/
 * 1. 문제:
 *   주어진 string에서 철자 수가 많은 것부터 정렬하여라.
 *
 * 2. 아이디어:
 *   pair를 쓴다.
 * */
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char> > vp;
        string res;
        int i, j;
        char ch;
        int cnt;

        sort(s.begin(), s.end());

        ch = s[0];
        cnt = 1;

        for (i = 1; i < s.size(); i++) {
            if (ch == s[i])
                cnt++;
            else {
                vp.push_back(make_pair(cnt, ch));
                ch = s[i];
                cnt = 1;
            }
        }

        vp.push_back(make_pair(cnt, ch));

        sort(vp.begin(), vp.end());

        for (i = vp.size() - 1; i >= 0; i--) {
            for (j = 0; j < vp[i].first; j++)
                res.push_back(vp[i].second);
        }

        return res;
    }
};