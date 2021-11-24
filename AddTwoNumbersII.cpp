/* Problem 445. Add Two Numbers II
 * https://leetcode.com/submissions/detail/591976572/
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
        ListNode *p, *q = NULL;
        stack<int> s1, s2;
        int up = 0, val = 0;

        p = l1;
        while (p) {
            s1.push(p->val);
            p = p->next;
        }

        p = l2;
        while (p) {
            s2.push(p->val);
            p = p->next;
        }

        while (!s1.empty() && !s2.empty()) {
            val = s1.top() + s2.top() + up;
            s1.pop();
            s2.pop();
            up = 0;

            if (val > 9) {
                up = 1;
                val -= 10;
            }

            p = new ListNode(val);
            p->next = q;
            q = p;
        }

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                val = s1.top() + up;
                s1.pop();
            }
            else {
                val = s2.top() + up;
                s2.pop();
            }
            up = 0;

            if (val > 9) {
                up = 1;
                val -= 10;
            }

            p = new ListNode(val);
            p->next = q;
            q = p;
        }

        if (up == 1) {
            p = new ListNode(1);
            p->next = q;
            q = p;
        }

        return q;
    }
};