/* Problem 3. Longest Substring Without Repeating Characters
 * https://leetcode.com/submissions/detail/564949732/
 * 1. 문제:
 *   string s에서 글자가 중복되지 않는 substring 중 최대 길이를 구하여라.
 *
 * 2. 아이디어:
 *   특정 글자가 마지막으로 나온 위치를 vector pos에 보관하고, 중복된 글자가 나올 경우 현재 substring의 시작 위치인 l보다 큰지 비교하여 클 경우
 *   현재 length를 재 계산한다.
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        vector<int> pos(256 + 1, -1);
        int l = -1, len = 0, max_len = -1;
        int i;

        if (size < 2)
            return size;

        for (i = 0; i < size; i++) {
            len++;
            if (pos[s[i]] > l) {
                l = pos[s[i]];
                len = i - l;
            }

            pos[s[i]] = i;

            if (len > max_len)
                max_len = len;
        }

        return max_len;
    }
};