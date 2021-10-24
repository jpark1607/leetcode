/* Problem 54. Spiral Matrix
 * https://leetcode.com/submissions/detail/576237670/
 * 1. 문제:
 *   주어진 vector를 소용돌이를 그리며 숫자를 따라간 결과를 출력하여라.
 *
 * 2. 아이디어:
 *   위치만 조심해서 쭉 따라간다.
 * */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int total = m * n;
        int cnt = 0;
        int i = 0, j = 0;
        int k = 0;

        while (1) {
            int i = k, j = k;
            for ( ; j < n; j++) {
                res.push_back(matrix[i][j]);
                cnt++;
            }
            i++;
            j--;

            if (total == cnt)
                break;
            for ( ; i < m; i++) {
                res.push_back(matrix[i][j]);
                cnt++;
            }
            i--;
            j--;

            if (total == cnt)
                break;
            for ( ; j >= k; j--) {
                res.push_back(matrix[i][j]);
                cnt++;
            }
            i--;
            j++;

            if (total == cnt)
                break;
            for ( ; i > k; i--) {
                res.push_back(matrix[i][j]);
                cnt++;
            }
            i++;
            j++;

            if (total == cnt)
                break;

            m--;
            n--;
            k++;
        }

        return res;
    }
};