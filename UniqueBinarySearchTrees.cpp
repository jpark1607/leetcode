/* Problem 96. Unique Binary Search Trees
 * https://leetcode.com/submissions/detail/569289176/
 * 1. 문제:
 *   n만큼의 노드 수가 있을 때, 만들 수 있는 모든 unique한 tree의 수를 구하여라.
 *
 * 2. 아이디어:
 *   n번째 노드가 root라고 할 때, 각 child를 뜯어보면 결국 1개 아니면 2개가 된다.
 *   (3개는 하나의 parent를 기준으로 1개 혹은 2개로 쪼갤 수 있음)
 * */
class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n + 1, 0);
        int i, j;

        if (n <= 2)
            return n;

        v[0] = 1;
        v[1] = 1;
        v[2] = 2;

        for (i = 3; i <= n; i++) {
            for (j = 1; j <= i; j++)
                v[i] += v[j - 1] * v[i - j];
        }

        return v[n];
    }
};