/* Problem 64. Minimum Path Sum
 * https://leetcode.com/submissions/detail/576276305/
 * 1. 문제:
 *   주어진 vector에서 경로의 합이 최소인 결과를 구하여라.
 *
 * 2. 아이디어:
 *   특정 포지션(index i, j)을 기준으로 (i - 1, j)와 (i, j - 1) 둘 중 작은 것을 더해간다.
 *   맨 윗 줄과 맨 왼쪽 줄은 누적 합을 쓴다.
 * */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        int i, j;

        for (i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];
        for (j = 1; j < n; j++)
            grid[0][j] += grid[0][j - 1];

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};