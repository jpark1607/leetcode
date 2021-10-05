/* Problem 118. Pascal's Triangle
 * https://leetcode.com/submissions/detail/566274459/
 * 1. 문제:
 *   파스칼의 삼각형을 2차원 vector로 return하여라.
 *
 * 2. 아이디어:
 *   1의 위치만 잘 파악하여 넣고, [i][j]의 위치는 [i - 1][j - 1] + [i - 1][j]로 넣는다.
 * */
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        vector<int> v(1, 1);
        int i;

        res.push_back(v);
        if (numRows == 1)
            return res;

        v.push_back(1);
        res.push_back(v);
        if (numRows == 2)
            return res;

        for (i = 2; i < numRows; i++) {
            v.clear();
            v.push_back(1);
            for (j = 1; j < i; j++) {
                v.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            v.push_back(1);
            res.push_back(v);
        }

        return res;
    }
};