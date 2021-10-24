/* Problem 59. Spiral Matrix II
 * https://leetcode.com/submissions/detail/576241835/
 * 1. 문제:
 *   주어진 정사각형 vector를 소용돌이를 그리며 1부터 채워나가라.
 *
 * 2. 아이디어:
 *   54번 문제와 비슷하다.
 * */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int total = n * n;
        int cnt = 1;
        int i = 0, j = 0;
        int k = 0;

        while (1) {
            int i = k, j = k;
            for ( ; j < n; j++) {
                res[i][j] = cnt;
                cnt++;
            }
            i++;
            j--;

            if (total < cnt)
                break;
            for ( ; i < n; i++) {
                res[i][j] = cnt;
                cnt++;
            }
            i--;
            j--;

            if (total < cnt)
                break;
            for ( ; j >= k; j--) {
                res[i][j] = cnt;
                cnt++;
            }
            i--;
            j++;

            if (total < cnt)
                break;
            for ( ; i > k; i--) {
                res[i][j] = cnt;
                cnt++;
            }
            i++;
            j++;

            if (total < cnt)
                break;

            n--;
            k++;
        }

        return res;
    }
};