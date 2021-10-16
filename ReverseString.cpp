/* Problem 344. Reverse String
 * https://leetcode.com/submissions/detail/571958945/
 * 1. 문제:
 *   주어진 string을 in-place로 뒤집어라.
 *
 * 2. 아이디어:
 *   두 개의 index를 놓고 양 끝에서 가까워지면서 swap한다.
 * */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        char tmp;

        while (l < r) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;

            l++;
            r--;
        }
    }
};