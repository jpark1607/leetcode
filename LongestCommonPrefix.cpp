/* Problem 14. Longest Common Prefix
 * https://leetcode.com/submissions/detail/565035191/
 * 1. 문제:
 *   주어진 string의 vector에서, 앞에서부터 모두 겹치는 substring을 return하여라.
 *
 * 2. 아이디어:
 *   다 비교해본다.
 * */
#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string res;
        int last_len, i, j;

        if (size == 1)
            return strs[0];

        last_len = strs[0].size();

        for (j = 0; j < last_len; j++)
            res.push_back(strs[0][j]);

        for (i = 1; i < size; i++) {
            for (j = 0; j < min((int)(strs[i].size()), last_len); j++) {
                if (strs[i][j] != res[j])
                    break;
            }
            last_len = j;
        }

        for (j = res.size(); j > last_len; j--)
            res.pop_back();

        return res;
    }
};