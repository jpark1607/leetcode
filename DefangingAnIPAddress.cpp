/* Problem 1108. Defanging an IP Address
 * https://leetcode.com/submissions/detail/583345517/
 * 1. 문제:
 *   주어진 IPv4 주소의 '.'을 '[.]'로 바꾼 string을 return하여라.
 *
 * 2. 아이디어:
 *   X
 * */
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        int size = address.size();
        int i;

        for (i = 0; i < size; i++) {
            switch (address[i]) {
            case '.':
                res.push_back('[');
                res.push_back('.');
                res.push_back(']');
                break;
            default:
                res.push_back(address[i]);
                break;
            }
        }

        return res;
    }
};