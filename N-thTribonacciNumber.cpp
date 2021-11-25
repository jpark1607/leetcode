/* Problem 1137. N-th Tribonacci Number
 * https://leetcode.com/submissions/detail/592464666/
 * 1. 문제:
 *   트리보나치(피보나치의 3개 버전) 수를 구하여라.
 *
 * 2. 아이디어:
 *   구한다. (memoization 포함)
 * */
class Solution {
public:
    int getTriboNum(int k, vector<int> &memo) {
        if (memo[n] == -1)
            memo[n] = getTriboNum(n - 1, memo) + getTriboNum(n - 2, memo) + getTriboNum(n - 3, memo);

        return memo[n];
    }

    int tribonacci(int n) {
        vector<int> memo(n + 1, -1);

        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;

        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;

        return getTriboNum(n, memo);
    }
};