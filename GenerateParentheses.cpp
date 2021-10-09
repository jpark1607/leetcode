/* Problem 22. Generate Parentheses
 * https://leetcode.com/submissions/detail/568172310/
 * 1. 문제:
 *   주어진 n만큼의 Parentheses 쌍이 있을 때, 이들의 조합 결과를 모두 출력하여라.
 *
 * 2. 아이디어:
 *   왼쪽 꺼 넣고 recursive, 오른쪽 꺼 넣고 recursive를 수행한다.
 *   단 수행 도중 왼쪽은 전체 개수보다 작거나 같아야 하며, 오른쪽은 왼쪽보다 항상 작거나 같아야 한다.
 * */
class Solution {
public:
    void makePartial(vector<string> &v, string s, int l, int r, int n) {

        if (s.length() == n * 2) {
            v.push_back(s);
            return;
        }

        if (l < n) {
            s.push_back('(');
            makePartial(v, s, l + 1, r, n);
            s.pop_back();
        }

        if (r < l) {
            s.push_back(')');
            makePartial(v, s, l, r + 1, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;

        makePartial(v, s, 0, 0, n);

        return v;
    }
};