/* Problem 1290. Convert Binary Number in a Linked List to Integer
 * https://leetcode.com/submissions/detail/580973326/
 * 1. 문제:
 *   주어진 list가 이진수를 나타낸다고 할 때, 십진수 결과를 구하여라.
 *
 * 2. 아이디어:
 *   따라가면서 x2 한다.
 * */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;

        while (head) {
            res *= 2;
            res += head->val;
            head = head->next;
        }

        return res;
    }
};