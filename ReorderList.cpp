/* Problem 143. Reorder List
 * https://leetcode.com/submissions/detail/568348429/
 * 1. 문제:
 *   주어진 list가 다음과 같을 때,
 *     L(0) -> L(1) -> L(2) -> ... -> L(n - 2) -> L(n - 1) -> L(n)
 *   다음과 같이 list를 재정렬하여라.
 *     L(0) -> L(n) -> L(1) -> L(n - 1) -> L(2) -> L(n - 2) -> ...
 *
 * 2. 아이디어:
 *   앞에서부터 절반은 queue, 나머지 절반은 stack에 넣고 하나씩 꺼내면서 넣는다.
 *   ps. 생각해보니 queue가 필요한가 싶다. 뒤에 절반만 stack에 넣고 앞에서부터 하나씩 건너뛰며 넣어주면 될 것 같다.
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
    void reorderList(ListNode* head) {
        int size = 0, i;
        stack<ListNode *> s;
        queue<ListNode *> q;
        ListNode *p = head, *c;

        while (p) {
            size++;
            p = p->next;
        }

        p = head->next;
        for (i = 1; i < ((size + 1) / 2); i++) {
            q.push(p);
            p = p->next;
        }
        for ( ; i < size; i++) {
            s.push(p);
            p = p->next;
        }

        p = head;
        while (!s.empty() || !q.empty()) {
            if (!s.empty()) {
                c = s.top();
                p->next = c;
                p = p->next;
                s.pop();
            }
            if (!q.empty()) {
                c = q.front();
                p->next = c;
                p = p->next;
                q.pop();
            }
        }

        p->next = NULL;
        return;
    }
};