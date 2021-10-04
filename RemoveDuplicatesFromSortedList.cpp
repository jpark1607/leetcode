/* Problem 83. Remove Duplicates from Sorted List
 * https://leetcode.com/submissions/detail/565641417/
 * 1. 문제:
 *   주어진 list에서 중복을 제거하여 return 하여라.
 *
 * 2. 아이디어:
 *   따라가면서 중복은 제외한다.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *res, *p;

        if (!head || !head->next)
            return head;

        res = new ListNode(head->val);
        p = res;

        while (head->next) {
            head = head->next;

            if (head->val != p->val) {
                p->next = new ListNode(head->val);
                p = p->next;
            }
        }

        return res;
    }
};