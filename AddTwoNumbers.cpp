/* Problem 2. Add Two Numbers
 * https://leetcode.com/submissions/detail/564899156/
 * 1. 문제:
 *   일의 자리부터 각 자리 수를 표현한 linked list가 두 개 있을 때, 두 수의 합을 구하여라.
 *
 * 2. 아이디어:
 *   list를 따라가면서 더한다.
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL, *p = NULL;
        int cur = l1->val + l2->val;
        bool upper = false;

        if (cur > 9) {
            cur -= 10;
            upper = true;
        }

        res = new ListNode(cur);
        p = res;

        l1 = l1->next;
        l2 = l2->next;

        while (!(l1 == NULL && l2 == NULL && !upper)) {
            cur = 0;

            if (upper) {
                cur++;
                upper = false;
            }

            if (l1 != NULL) {
                cur += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                cur += l2->val;
                l2 = l2->next;
            }

            if (cur > 9) {
                cur -= 10;
                upper = true;
            }

            p->next = new ListNode(cur);
            p = p->next;
        }

        return res;
    }
};