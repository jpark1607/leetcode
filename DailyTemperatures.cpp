/* Problem 739. Daily Temperatures
 * https://leetcode.com/submissions/detail/586799058/
 * 1. 문제:
 *   주어진 vector가 i번째 날의 날씨를 뜻한다고 할 때, i번째 날에서부터 그보다 따뜻해지는 날의 차이를 각각 구하여라.
 *
 * 2. 아이디어:
 *   stack을 써서 각 날짜보다 따뜻해지는 날에 pop을 한다.
 * */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size, 0);
        stack<int> tmp;
        int i;

        tmp.push(0);

        for (i = 1; i < size; i++) {
            while (temperatures[i] > temperatures[tmp.top()]) {
                res[tmp.top()] = i - tmp.top();
                tmp.pop();
                if (tmp.empty())
                    break;
            }
            tmp.push(i);
        }

        return res;
    }
};