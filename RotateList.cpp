/* Problem 61. Rotate List
 * https://leetcode.com/submissions/detail/586827301/
 * 1. 문제:
 *   주어진 list를 k회만큼 오른쪽으로 회전(tail node를 head로 가져옴)시킬 때의 결과를 return 하여라.
 *
 * 2. 아이디어:
 *   tail의 next에 head를 위치시키고, (size - k - 1)번째 node와 그 다음 node의 연결을 끊은 뒤 그 다음 node를 head로 하여 return한다.
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *node = head, *next;
        int size = 1;

        if (!head)
            return head;

        while (node->next) {
            node = node->next;
            size++;
        }

        if (size < 2)
            return head;

        k = size - (k % size);
        if (k == size)
            return head;
        k--;

        node->next = head;
        node = head;
        while (k > 0) {
            node = node->next;
            k--;
        }

        next = node->next;
        node->next = NULL;

        return next;
    }
};