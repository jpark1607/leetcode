/* Problem 6. ZigZag Conversion
 * https://leetcode.com/submissions/detail/565014567/
 * 1. 문제:
 *   글자를 지그재그로 배치한 뒤, row 순서대로 읽은 결과를 return하라.
 *   예를 들면 다음과 같다.
 *   ex1> "PAYPALISHIRING", n=3
 *   P   A   H   N
 *   A P L S I I G
 *   Y   I   R
 *   -> "PAHNAPLSIIGYIR"
 *   ex2> "PAYPALISHIRING", n=4
 *   P     I    N
 *   A   L S  I G
 *   Y A   H R
 *   P     I
 *   -> "PINALSIGYAHRPI"
 *
 * 2. 아이디어:
 *   지그재그로 배치했을 때 k번째 row의 글자 규칙은 다음과 같다.
 *   첫번째 글자는 k - 1번째 index이다.
 *   두번째 글자는 위 첫번째 글자에서 (n - k - 1) * 2보다 뒤의 것이다. -- 패턴 #1(gap1)
 *   세번째 글자는 위 두번째 글자에서 k * 2보다 뒤의 것이다. -- 패턴 #2(gap2)
 *   이후 패턴 #1과 패턴 #2가 반복된다.
 *   추가로 첫번째 row는 패턴 #2가 생략(gap2가 0)되고, 마지막 row는 패턴 #1이 생략(gap1이 0)되는 것만 주의하면 된다.
 * */
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int size = s.size();
        int pos, gap1, gap2;
        int i;

        if (numRows == 1)
            return s;

        for (i = 0; i < numRows; i++) {
            pos = i;
            gap1 = (numRows - i - 1) * 2;
            gap2 = i * 2;

            while (1) {
                if (pos < size) {
                    if (gap1 > 0) {
                        res.push_back(s[pos]);
                        pos += gap1;
                    }
                }
                else
                    break;

                if (pos < size) {
                    if (gap2 > 0) {
                        res.push_back(s[pos]);
                        pos += gap2;
                    }
                }
                else
                    break;
            }
        }

        return res;
    }
};