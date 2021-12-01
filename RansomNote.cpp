/* Problem 383. Ransom Note
 * https://leetcode.com/submissions/detail/595428547/
 * 1. 문제:
 *   주어진 string ransomNote가 magazine에 포함된 철자들로 이루어질 수 있는지 확인하여라.
 *
 * 2. 아이디어:
 *   배열에 넣고, 하나씩 빼 보면서 체크한다.
 * */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letters(26, 0);
        int size = magazine.size();
        int i;

        for (i = 0; i < size; i++)
            letters[magazine[i] - 'a']++;

        size = ransomNote.size();

        for (i = 0; i < size; i++) {
            letters[ransomNote[i] - 'a']--;
            if (letters[ransomNote[i] - 'a'] < 0)
                return false;
        }

        return true;
    }
};