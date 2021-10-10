/* Problem 237. Delete Node in a Linked List
 * https://leetcode.com/submissions/detail/568812737/
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev = node, *cur = node->next;

        while (cur->next) {
            prev->val = cur->val;
            prev = prev->next;
            cur = cur->next;
        }

        prev->val = cur->val;
        prev->next = NULL;

        delete cur;
    }
};