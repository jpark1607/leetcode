/* Problem 2. Add Two Numbers
 * 1. 문제:
 *
 *
 * 2. 아이디어:
 *
 *
 * 3. 상세 코드:
 *   [A]
 *     [A-1]
 *   [B]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res, *p;
        int cur;
        bool upper = false;

        do {
            cur = 0;
            if (upper) {
                cur++;
                upper = false;
            }

            if (l1->next != NULL) {

            }
            if (l2->next != NULL) {

            }

        }
        while (l1->next != NULL && l2->next != NULL);

        return res;
    }
};