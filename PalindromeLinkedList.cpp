/* Problem 234. Palindrome Linked List
 * https://leetcode.com/submissions/detail/580964983/
 * 1. 문제:
 *   주어진 list가 palindrome인지 확인하여라.
 *
 * 2. 아이디어:
 *   첫번째 순환 때 stack에 넣고, 두번째 순환 때 stack과 비교하며 pop한다.
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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *p = head;

        while (p) {
            s.push(p->val);
            p = p->next;
        }

        p = head;

        while (p) {
            if (s.top() != p->val)
                return false;
            s.pop();
            p = p->next;
        }

        return true;
    }
};