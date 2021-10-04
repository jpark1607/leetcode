/* Problem 66. Plus One
 * https://leetcode.com/submissions/detail/565148547/
 * 1. 문제:
 *   주어진 vector가 자연수를 나타낼 때, 여기에 1을 더한 값을 vector로 표현하여라.
 *
 * 2. 아이디어:
 *   맨 뒤에 1을 더하고 자리가 올라가는 경우만 앞 자리에 1씩 더해주면 된다.
 *   999...999에 1을 더하는 경우만 자리수가 바뀌어서 문제가 되는데, 이 경우 결과는 무조건 10의 N승이기 때문에 맨 앞을 1로 치환하고
 *   맨 뒤에 0을 하나 더 넣어준다.
* */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i = size - 1;

        digits[i] += 1;

        while (i >= 1) {
            if (digits[i] < 10)
                break;
            digits[i] = 0;
            i--;
            digits[i] += 1;
        }

        if (digits[0] == 10) {
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};