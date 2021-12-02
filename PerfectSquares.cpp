/* Problem 279. Perfect Squares
 * [http://submissions/here]
 * 1. 문제:
 *
 *
 * 2. 아이디어:
 *
 *
 * 3. 상세 코드:
 *   [A]
 *     [A-1]
 *   [B]
 * */
class Solution {
private:
    vector<int> v;
    int cnt;
public:
    int numSquares(int n) {
        this->v.assign(sqrt(n) + 1, 0);
        this->cnt = 0;

        for (int i = 1; i < this->v.size(); i++) {
            this->v[i] = i * i;
        }

        return 1;
    }
};