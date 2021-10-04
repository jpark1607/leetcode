/* Problem 70. Climbing Stairs
 * https://leetcode.com/submissions/detail/565536694/
 * 1. 문제:
 *   계단을 한 번에 한 칸 혹은 두 칸만 오를 수 있다. n칸의 계단이 있을 때 오를 수 있는 경우의 수를 구하여라.
 *
 * 2. 아이디어:
 *   경우의 수가 fibonacci 수와 동일하다. 여기에 memoization 까지만 같이 써 준다.
 * */
class Solution {
public:
    int stairRecursive(int n, vector<int> &R) {
        if (R[n] > 0)
            return R[n];

        R[n] = stairRecursive(n - 1, R) + stairRecursive(n - 2, R);

        return R[n];
    }

    int climbStairs(int n) {
        vector<int> R(n + 2, 0);
        R[1] = 1;
        R[2] = 2;

        return stairRecursive(n, R);
    }
};