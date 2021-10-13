/* Problem 48. Rotate Image
 * https://leetcode.com/submissions/detail/570618195/
 * 1. 문제:
 *   vector를 오른쪽으로 90도 돌린 결과대로 vector 내의 값들을 변경하여라.
 *   (2d vector 추가 선언 금지)
 *
 * 2. 아이디어:
 *   vector row 수의 절반만 loop를 돌고(큰 정사각형부터 한 칸 씩 들어가는 것)
 *   그 내에서 column - 1 수만큼 또 loop를 돈다.(한 row 내에 있는 수보다 하나 작은 것)
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size() - 1;
        int i, j;
        int left = -1, right = size, half = (size + 1) / 2;
        int tmp;

        for (i = 0; i < half; i++) {
            left++;
            right--;

            for (j = left; j <= right; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[size - j][i];
                matrix[size - j][i] = matrix[size - i][size - j];
                matrix[size - i][size - j] = matrix[j][size - i];
                matrix[j][size - i] = tmp;
            }
        }

        return;
    }
};