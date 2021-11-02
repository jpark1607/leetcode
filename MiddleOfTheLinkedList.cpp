/* Problem 876. Middle of the Linked List
 * https://leetcode.com/submissions/detail/580972059/
 * 1. 문제:
 *   list의 중간 지점 포인터를 return하여라.
 *
 * 2. 아이디어:
 *   두 포인터를 만들고 p 1회, q 1회, p 1회 이런 식으로 반복한다(p->next가 있을 때까지)
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
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head, *q = head;

        while (p->next) {
            p = p->next;
            q = q->next;
            if (p->next)
                p = p->next;
        }

        return q;
    }
};