/* Problem 412. Fizz Buzz
 * https://leetcode.com/submissions/detail/595473946/
 * 1. 문제:
 *   1부터 n까지의 수에 대해 각각에 대하여 아래 조건을 만족하는 경우 그 string을 넣고, 아니면 수를 넣어라.
 *   - 3으로 나누어 떨어지면 "Fizz"
 *   - 5로 나누어 떨어지면 "Buzz"
 *   - 3과 5 둘 다 나누어 떨어지면 "FizzBuzz"
 *
 * 2. 아이디어:
 *   15의 나머지, 3의 나머지, 5의 나머지가 0일 경우 순서대로 체크한다.
 * */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int i;
        vector<string> res;

        for (i = 1; i <= n; i++) {
            if (i % 15 == 0)
                res.push_back("FizzBuzz");
            else if (i % 3 == 0)
                res.push_back("Fizz");
            else if (i % 5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }

        return res;
    }
};