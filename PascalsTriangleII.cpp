/* Problem 119. Pascal's Triangle II
 * https://leetcode.com/submissions/detail/566279521/
 * 1. 문제:
 *   파스칼의 삼각형에서 rowIndex번째 row의 vector를 return하여라.
 *
 * 2. 아이디어:
 *   118번 문제와 똑같이 2차원 vector를 써도 되지만, 최소한의 메모리 사용을 위해 1차원 vector만 썼다.
 *   (Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?)
 *   단, 왼쪽에서부터 더해 나가다 보면 덮어씌워지기 때문에 계산이 잘못되므로, 뒤에서부터 계산하도록 하였다.
 *   2차원 vector를 사용하는 코드는 118번 문제와 같으므로 만들지 않겠다.
 * */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        int i, j;

        if (rowIndex < 2)
            return res;

        for (i = 2; i <= rowIndex; i++) {
            for (j = i - 1; j > 0; j--) {
                res[j] = res[j] + res[j - 1];
            }
        }

        return res;
    }
};