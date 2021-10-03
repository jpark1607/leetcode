#include <vector>

/* Problem 9. Palindrome Number
 * 1. 문제:
 *   주어진 수가 palindrome인지 확인하여라.
 *
 * 2. 아이디어:
 *   vector에 넣고 비교해본다.
 * */
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> num(10, 0);
        int i, size = 0;

        if (x < 0)
            return false;
        else if (x < 10)
            return true;

        while (x > 0) {
            num[size] = x % 10;
            x /= 10;
            size++;
        }

        for (i = 0; i < size / 2; i++) {
            if (num[i] != num[size - i - 1])
                return false;
        }

        return true;
    }
};