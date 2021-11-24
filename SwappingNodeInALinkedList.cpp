/* Problem 1721. Swapping Nodes in a Linked List
 * https://leetcode.com/submissions/detail/591979634/
 * 1. 문제:
 *   앞에서부터 k번째 노드와 뒤에서부터 k번째 노드의 값을 바꾼 list를 return하여라.
 *
 * 2. 아이디어:
 *   처음 순회를 하면서 총 노드의 개수를 구하되, k번째 노드를 같이 찾는다.
 *   이후 다시 순회를 하면서 (n + 1 - k)번째 노드를 찾는다.
 *   그리고 두 노드의 값을 swap한다.
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p2 = head, *p1;
        int n = 0, x = k;

        while (p2) {
            n++;
            x--;

            if (x == 0)
                p1 = p2;

            p2 = p2->next;
        }

        x = n + 1 - k;

        p2 = head;
        while (p2) {
            x--;
            if (x == 0)
                break;

            p2 = p2->next;
        }

        swap(p1->val, p2->val);

        return head;
    }
};