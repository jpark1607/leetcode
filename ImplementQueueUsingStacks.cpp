/* Problem 232. Implement Queue using Stacks
 * https://leetcode.com/submissions/detail/568364049/
 * 1. 문제:
 *   stack을 이용해서 queue를 구현하여라.
 *
 * 2. 아이디어:
 *   push할 때 stack을 두 번 옮기는 걸로 queue.pop 상태를 유지한다.
 * */
class MyQueue {
private:
    stack<int> curQ;
    stack<int> tmpQ;
public:
    MyQueue() {
        /* intialize : nothing to do */
    }

    void push(int x) {
        while (!curQ.empty()) {
            tmpQ.push(curQ.top());
            curQ.pop();
        }
        tmpQ.push(x);
        while (!tmpQ.empty()) {
            curQ.push(tmpQ.top());
            tmpQ.pop();
        }
        return;
    }

    int pop() {
        int res = curQ.top();
        curQ.pop();
        return res;
    }

    int peek() {
        return curQ.top();
    }

    bool empty() {
        return curQ.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */