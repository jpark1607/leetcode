/* Problem 121. Best Time to Buy and Sell Stock
 * https://leetcode.com/submissions/detail/579789965/
 * 1. 문제:
 *   주어진 vector가 각 날짜의 주식의 가격을 나타난다고 할 때, 최대 이익을 구하여라.
 *
 * 2. 아이디어:
 *   max profit을 계속 계산하는 변수와 min value를 계속 계산하는 변수를 갱신하면서 구한다.
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int min_val = 0, max_prof = 0;
        int i;

        if (size < 2)
            return 0;

        min_val = prices[0];

        for (i = 1; i < size; i++) {
            if (prices[i] - min_val > max_prof)
                max_prof = prices[i] - min_val;
            else if (prices[i] < min_val)
                min_val = prices[i];
        }

        return max_prof;
    }
};