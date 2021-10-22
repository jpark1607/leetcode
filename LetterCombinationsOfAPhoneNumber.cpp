/* Problem 17. Letter Combinations of a Phone Number
 * https://leetcode.com/submissions/detail/575353950/
 * 1. 문제:
 *   전화 각 번호에는 대응되는 영문자가 있다(고대인..?).
 *   특정 수가 입력되었을 때, 가능한 영문자의 조합을 모두 구하여라.
 *
 * 2. 아이디어:
 *   recursive
 * */
class Solution {
public:
    void makeCombination(vector<string> &res, string comb, string digits, int idx) {
        int i = 0;

        if (idx == digits.size()) {
            res.push_back(comb);
            return;
        }

        comb.push_back('X');

        switch (digits[idx]) {
        case '2':
            for ( ; i < 3; i++) {
                comb[idx] = 'a' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        case '3':
            for ( ; i < 3; i++) {
                comb[idx] = 'd' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        case '4':
            for ( ; i < 3; i++) {
                comb[idx] = 'g' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        case '5':
            for ( ; i < 3; i++) {
                comb[idx] = 'j' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        case '6':
            for ( ; i < 3; i++) {
                comb[idx] = 'm' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        case '7':
            for ( ; i < 4; i++) {
                comb[idx] = 'p' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        case '8':
            for ( ; i < 3; i++) {
                comb[idx] = 't' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        case '9':
            for ( ; i < 4; i++) {
                comb[idx] = 'w' + i;
                makeCombination(res, comb, digits, idx + 1);
            }
            break;
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string comb;

        if (digits.size() > 0)
            makeCombination(res, comb, digits, 0);

        return res;
    }
};