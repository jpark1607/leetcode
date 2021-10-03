/* Problem 58. Length of Last Word
 * https://leetcode.com/submissions/detail/565144244/
 * 1. 문제:
 *   주어진 string 내에서 가장 마지막에 위치한 단어의 길이를 구하여라.
 *
 * 2. 아이디어:
 *   뒤에서부터 trailing white space가 안 나오는 첫번째 위치를 찾고, 거기서부터 다음 white space가 나오는 위치를 찾은 뒤 뺀다.
 * */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int pos = 0;
        int i = size - 1;

        while (i >= 0 && s[i] == ' ')
            i--;

        pos = i;

        while (i >= 0 && s[i] != ' ')
            i--;

        return pos - i;
    }
};