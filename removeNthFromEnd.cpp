/* Problem 19. Remove Nth Node From End of List
 * https://leetcode.com/submissions/detail/565356086/
 * 1. 문제:
 *   list의 뒤에서부터 n번째 요소를 제거한 list를 return하여라.
 *
 * 2. 아이디어:
 *   n개만큼 앞서간 포인터(r)와 head부터 시작하는 포인터(l)을 반복해서 옮기면 된다.
 *   r의 next가 NULL일 때, l의 next를 지우면 된다.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = head, *r = head;
        int i;

        for (i = 0; i < n - 1; i++)
            r = r->next;

        if (!r->next)
            return head->next;

        while (1) {
            r = r->next;
            if (!r->next)
                break;
            l = l->next;
        }

        l->next = l->next->next;

        return head;
    }
};