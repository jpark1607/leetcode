/* Problem 86. Partition List
 * https://leetcode.com/submissions/detail/579323148/
 * 1. 문제:
 *   주어진 list에서 x보다 작은 값을 앞으로, x보다 크거나 같은 값을 뒤로 재정렬하여라.
 *   기존 list의 정렬 순서는 유지해야 한다.
 *
 * 2. 아이디어:
 *   두 가지 방법이 있다.
 *     a) 두 list를 만들어서 이어 주는 방법
 *     b) inplace 교체 방법
 *   b)의 방법으로 하였는데, 왼쪽의 마지막을 유지하는 포인터(p)와 오른쪽의 바꿀 대상 포인터(r)와 그 직전 포인터(q)를 가지고 작업한다.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p, *q, *r;

        if (!head)
            return head;

        p = new ListNode(-111);
        p->next = head;
        head = p;

        while (p->next && p->next->val < x)
            p = p->next;

        q = p->next;
        if (!q)
            return head->next;

        r = q->next;
        while (r) {
            if (r->val < x) {
                q->next = r->next;

                r->next = p->next;
                p->next = r;
                p = p->next;
            }
            else {
                q = q->next;
                if (!q)
                    break;
            }
            r = q->next;
        }


        return head->next;
    }
};