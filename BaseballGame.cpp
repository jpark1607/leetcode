/* Problem 682. Baseball Game
 * https://leetcode.com/submissions/detail/579819565/
 * 1. 문제:
 *   string으로 이루어진 vector의 각 인자를 돌며 다음을 연산한다.
 *     "+" : 직전 두 수의 합을 추가한다.
 *     "D" : 직전 수의 2배를 추가한다.
 *     "C" : 직전 수를 제거한다.
 *   결과 집합의 합을 구하여라.
 *
 * 2. 아이디어:
 *   X
 * */
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        int size1 = ops.size(), size2 = 0;
        int i = 0;
        int val = 0;

        for (i = 0; i < size1; i++) {
            if (ops[i] == "+") {
                res.push_back(res[size2 - 1] + res[size2 - 2]);
                size2++;
            }
            else if (ops[i] == "D") {
                res.push_back(res[size2 - 1] * 2);
                size2++;
            }
            else if (ops[i] == "C") {
                res.pop_back();
                size2--;
            }
            else {
                res.push_back(stoi(ops[i]));
                size2++;
            }
        }

        for (i = 0; i < size2; i++) {
            val += res[i];
        }

        return val;
    }
};