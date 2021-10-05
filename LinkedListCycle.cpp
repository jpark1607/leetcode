/* Problem 141. Linked List Cycle
 * https://leetcode.com/submissions/detail/566286866/
 * 1. 문제:
 *   linked list에 cycle이 있는지 확인해 보아라.
 *
 * 2. 아이디어:
 *   value(혹은 포인터 주소)를 메모리에 기억해놔도 되지만, 포인터 두 개로 따라가는 것이 워낙 유명하므로 그 방식으로만 구현했다.
 *   (Follow up: Can you solve it using O(1) (i.e. constant) memory?)
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
    bool hasCycle(ListNode *head) {
        ListNode *p, *q;

        if (!head || !head->next)
            return false;

        p = head->next;
        q = head->next;
        if (!q)
            return false;
        q = q->next;

        while (p && q) {
            if (p == q)
                return true;
            p = p->next;
            q = q->next;
            if (!q)
                return false;
            q = q->next;
        }

        return false;
    }
};