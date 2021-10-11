/* Problem 206. Reverse Linked List
 * https://leetcode.com/submissions/detail/569311039/
 * 1. 문제:
 *   주어진 list를 거꾸로 하여라.
 *
 * 2. 아이디어:
 *   하나씩 따라가면서 그 node의 next를 head로 설정해 준다.
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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur, *next;

        if (!head || !head->next)
            return head;

        cur = head->next;
        head->next = NULL;

        while (cur) {
            next = cur->next;
            cur->next = head;
            head = cur;
            cur = next;
        }

        return head;
    }
};