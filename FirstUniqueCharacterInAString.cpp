/* Problem 387. First Unique Character in a String
 * https://leetcode.com/submissions/detail/569262248/
 * 1. 문제:
 *   주어진 string에서 처음 unique한 글자가 나오는 index를 반환하여라.
 *
 * 2. 아이디어:
 *   소문자의 위치를 담을 배열을 만들고, 처음 나오는 index의 위치를 기록한다. 두 번 이상 나오면 INT_MAX - 1을 넣는다.
 * */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ascii(26, INT_MAX);
        int size = s.size();
        int num;
        int i;

        for (i = 0; i < size; i++) {
            num = s[i] - 'a';

            if (ascii[num] == INT_MAX)
                ascii[num] = i;
            else if (ascii[num] >= 0)
                ascii[num] = INT_MAX - 1;
        }

        num = INT_MAX;
        for (i = 0; i < 26; i++) {
            if (num > ascii[i])
                num = ascii[i];
        }

        if (num >= (INT_MAX - 1))
            return -1;
        else
            return num;
    }
};