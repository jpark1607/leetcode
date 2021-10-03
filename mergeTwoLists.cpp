/* Problem 21. Merge Two Sorted Lists
 * [http://submissions/here]
 * 1. 문제:
 *   오름차순으로 정렬된 두 list를 merge하여라.
 *
 * 2. 아이디어:
 *   두 개 따라가면서 더 작은 쪽을 새로운 list에 insert한다.
 *   한 쪽에 껴넣는 방법도 있을 것 같은데.. 일단 그냥 한다.
 */
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
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res, *p, *q;

        if (l1 == NULL && l2 == NULL)
            return res;

        p = new ListNode();
        res = p;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                q = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                q = new ListNode(l2->val);
                l2 = l2->next;
            }
            p->next = q;
            p = p->next;
        }

        p->next = l2 ? l2 : l1;

        return res->next;
    }
};