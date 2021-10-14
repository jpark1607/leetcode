/* Problem 509. Fibonacci Number
 * https://leetcode.com/submissions/detail/571193522/
 * 1. 문제:
 *   피보나치 수를 구하여라.
 *
 * 2. 아이디어:
 *   구한다. (memoization 포함)
 * */
class Solution {
public:
    int getFiboNum(int n, vector<int> &memo) {
        if (memo[n] == 0)
            memo[n] = getFiboNum(n - 1, memo) + getFiboNum(n - 2, memo);

        return memo[n];
    }

    int fib(int n) {
        vector<int> memo(n + 1, 0);

        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;

        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;

        return getFiboNum(n, memo);
    }
};