/* Problem 38. Count and Say
 * https://leetcode.com/submissions/detail/576230941/
 * 1. 문제:
 *   주어진 수를 "몇 개의 수 N이 있다"로 반복되는 string을 n회 반복한 결과를 출력하여라.
 *
 * 2. 아이디어:
 *   recursive
 * */
class Solution {
public:
    string countAndSay(int n) {
        string res, old;
        int size, i;
        char chr;
        int cnt;

        if (n == 1) {
            return "1";
        }
        old = countAndSay(n - 1);
        size = old.size();

        chr = old[0];
        cnt = 1;
        for (i = 1; i < size; i++) {
            if (chr == old[i])
                cnt++;
            else {
                res.push_back(cnt + '0');
                res.push_back(chr);
                chr = old[i];
                cnt = 1;
            }
        }
        res.push_back(cnt + '0');
        res.push_back(chr);

        return res;
    }
};