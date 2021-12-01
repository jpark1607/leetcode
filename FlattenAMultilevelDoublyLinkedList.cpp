/* Problem 430. Flatten a Multilevel Doubly Linked List
 * https://leetcode.com/submissions/detail/595472209/
 * 1. 문제:
 *   double linked list에 child가 있을 때, child를 flatten하게 펼친 결과 list를 return하여라.
 *
 * 2. 아이디어:
 *   child가 있는 cur 노드에서는 next와 child를 빼낸 뒤, cur와 child를 먼저 연결시킨다.
 *   그리고 child의 last까지 간 뒤에 next와 연결시킨다.
 * */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head, *next, *child;

        while (cur) {
            if (cur->child) {
                next = cur->next;
                child = cur->child;
                cur->child = NULL;
                cur->next = child;
                child->prev = cur;

                while (child->next)
                    child = child->next;

                child->next = next;
                if (next)
                    next->prev = child;
            }
            cur = cur->next;
        }

        return head;
    }
};