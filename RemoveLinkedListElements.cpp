/* Problem 203. Remove Linked List Elements
 * https://leetcode.com/submissions/detail/568806792/
 * 1. 문제:
 *   주어진 list에서 주어진 val과 동일한 인자는 제거하여라.
 *
 * 2. 아이디어:
 *   동일한 값의 인자가 나오면 prev->next에 cur->next를 달아준다.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev, *cur;

        if (!head)
            return NULL;

        prev = new ListNode(-1);
        prev->next = head;
        head = prev;
        cur = prev->next;

        while (cur) {
            if (cur->val == val)
                prev->next = cur->next;
            else
                prev = prev->next;
            cur = prev->next;
        }

        return head->next;
    }
};