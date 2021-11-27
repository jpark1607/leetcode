/* Problem 1441. Build an Array With Stack Operations
 * https://leetcode.com/submissions/detail/593281418/
 * 1. 문제:
 *   주어진 vector를 만들기 위해 stack을 사용한 결과를 출력하여라.
 *
 * 2. 아이디어:
 *   매 값을 push하고, 맞지 않는 값은 pop한다.
 * */
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size = target.size();
        int i;
        vector<string> res;
        int n = 1;

        for (i = 0; i < size; i++) {
            while (1) {
                res.push_back("Push");
                if (target[i] != n) {
                    res.push_back("Pop");
                    n++;
                }
                else {
                    n++;
                    break;
                }
            }
        }

        return res;
    }
};