/* Problem 62. Unique Paths
 * https://leetcode.com/submissions/detail/575358119/
 * 1. 문제:
 *   m x n 의 직사각형이 있을 때, unique한 경로의 수를 구하여라.
 *
 * 2. 아이디어:
 *   특정 위치의 독립된 경로의 수는 (윗 칸의 경로의 수) + (왼쪽 칸의 경로의 수) 이다.
 * */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **paths = new int *[m];
        //vector<vector<int>> paths(n ,vector<int>(m));
        int i, j;

        for (i = 0; i < m; i++) {
            paths[i] = new int[n];
            paths[i][0] = 1;
        }
        for (j = 0; j < n; j++)
            paths[0][j] = 1;

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++)
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }

        return paths[m - 1][n - 1];
    }
};