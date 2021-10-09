/* Problem 147. Insertion Sort List
 * https://leetcode.com/submissions/detail/568189820/
 * 1. 문제:
 *   linked list를 insertion sort 방식으로 정렬하여라.
 *
 * 2. 아이디어:
 *   head부터 하나씩 link를 따라가며 n번째 인자를 판단할 포인터(r_cur) 그리고 그 앞의 포인터(r_prev),
 *   매 번 head부터 탐색하면서 값이 작은지 판단의 대상이 될 포인터(l_cur) 그리고 그 앞의 포인터(l_prev)
 *   총 4개가 필요하다.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *l_prev, *l_cur, *r_prev, *r_cur;

        l_cur = new ListNode(-5001);
        l_cur->next = head;
        head = l_cur;

        r_prev = head;
        r_cur = r_prev->next;

        while (r_cur) {
            l_prev = head;
            l_cur = l_prev->next;

            while (l_cur->val < r_cur->val) {
                l_prev = l_cur;
                l_cur = l_cur->next;
            }

            if (l_cur == r_cur) {
                r_prev = r_cur;
                r_cur = r_cur->next;
                continue;
            }

            r_prev->next = r_cur->next;

            l_prev->next = r_cur;
            r_cur->next = l_cur;

            r_cur = r_prev->next;
        }

        return head->next;
    }
};