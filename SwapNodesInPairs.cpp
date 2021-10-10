/* Problem 24. Swap Nodes in Pairs
 * https://leetcode.com/submissions/detail/568740921/
 * 1. 문제:
 *   n - 1번째 node와 n번째 node의 위치를 바꾸어라.
 *
 * 2. 아이디어:
 *   n - 1번째를 p1, n번째를 p2로 놓고, n - 2번째(prev), n + 1번째(next)도 같이 설정한 뒤 prev -> p2 -> p1 -> next가 되도록 한다.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev, *p1, *p2, *next;

        if (!head || !head->next)
            return head;

        prev = new ListNode(-1);
        prev->next = head;

        p1 = head;
        p2 = p1->next;
        next = p2->next;
        head = p2;

        while (p1 && p2) {
            prev->next = p2;
            p2->next = p1;
            p1->next = next;

            prev = p1;
            p1 = prev->next;
            if (p1)
                p2 = p1->next;
            if (p2)
                next = p2->next;
        }

        return head;
    }
};