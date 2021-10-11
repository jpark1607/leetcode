/* Problem 120. Triangle
 * https://leetcode.com/submissions/detail/569295098/
 * 1. 문제:
 *   2차원 vector로 만든 삼각형에서, 꼭지점부터 가장 아래까지의 합 중 최소를 구하여라.
 *
 * 2. 아이디어:
 *   맨 밑에서부터 하나씩 올라가며 min 값을 더해준다.
 * */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        int i, j;

        if (size == 1)
            return triangle[0][0];

        for (i = size - 2; i >= 0; i--) {
            for (j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};