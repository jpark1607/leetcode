/* Problem 63. Unique Paths II
 * https://leetcode.com/submissions/detail/575361398/
 * 1. 문제:
 *   m x n 의 직사각형이 있을 때, unique한 경로의 수를 구하여라. 단 중간에 장애물이 있다.
 *
 * 2. 아이디어:
 *   [62. Unique Paths] 문제와 같다. 단, 장애물이 있는 위치만 0으로 유지시켜주면 된다.
 * */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int i, j;
        int tmp;

        if (obstacleGrid[0][0] == 1)
            return 0;

        obstacleGrid[0][0] = 1;

        tmp = 1;
        for (i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                tmp = 0;
            obstacleGrid[i][0] = tmp;
        }

        tmp = 1;
        for (j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1)
                tmp = 0;
            obstacleGrid[0][j] = tmp;
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++)
                obstacleGrid[i][j] ^= 1;
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};
        return obstacleGrid[m - 1][n - 1];
    }
};