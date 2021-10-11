/* Problem 92. Reverse Linked List II
 * https://leetcode.com/submissions/detail/569317652/
 * 1. 문제:
 *   주어진 list에서 left ~ right까지의 범위 node들만 reverse하여라.
 *
 * 2. 아이디어:
 *   left의 이전 node(leftLast)와 right의 다음 node(rightFirst)를 기억해 놓고, left의 첫번째 노드(leftLast->next)부터 하나씩
 *   rightFirst를 next로 가리키게 한 뒤, 그 노드를 rightFirst로 지정하는 것을 반복한다.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *leftLast, *cur, *next, *rightFirst;
        int i;

        if (left == right)
            return head;

        leftLast = new ListNode(-501);
        leftLast->next = head;
        head = leftLast;

        for (i = 1; i < left; i++)
            leftLast = leftLast->next;

        rightFirst = leftLast->next;

        for (i = left; i <= right; i++)
            rightFirst = rightFirst->next;

        cur = leftLast->next;

        for (i = left; i <= right; i++) {
            next = cur->next;
            cur->next = rightFirst;
            rightFirst = cur;
            cur = next;
        }

        leftLast->next = rightFirst;

        return head->next;
    }
};