/* Problem 328. Odd Even Linked List
 * https://leetcode.com/submissions/detail/591973282/
 * 1. 문제:
 *   주어진 list에서 홀수번째 index의 list들을 연결시키고, 짝수번째 index의 list를 연결시킨 뒤 홀수번째의 맨 뒤에 짝수번째를 연결시켜라.
 *
 * 2. 아이디어:
 *   번갈아가면서 달아주고, 마지막에 이어준다.
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd, *even, *cur, *next;

        if (!head || !head->next)
            return head;

        odd = head;
        even = head->next;
        cur = even->next;
        next = even;

        odd->next = NULL;
        even->next = NULL;

        while (1) {
            if (!cur)
                break;

            odd->next = cur;
            cur = cur->next;
            odd = odd->next;
            odd->next = NULL;

            if (!cur)
                break;

            even->next = cur;
            cur = cur->next;
            even = even->next;
            even->next = NULL;
        }

        odd->next = next;

        return head;
    }
};