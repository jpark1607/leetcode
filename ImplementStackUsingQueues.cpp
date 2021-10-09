/* Problem 225. Implement Stack using Queues
 * https://leetcode.com/submissions/detail/568368441/
 * 1. 문제:
 *   queue를 이용해서 stack을 구현하여라.
 *
 * 2. 아이디어:
 *   push를 할 때마다 빈 queue에 넣고, 이전에 넣었던 것들을 다시 넣어 준다.
 * */
class MyStack {
private:
    queue<int> curS;
    queue<int> tmpS;
public:
    MyStack() {
        /* intialize : nothing to do */
    }

    void push(int x) {
        tmpS.push(x);
        while (!curS.empty()) {
            tmpS.push(curS.front());
            curS.pop();
        }
        swap(curS, tmpS);
        return;
    }

    int pop() {
        int res = curS.front();
        curS.pop();
        return res;
    }

    int top() {
        return curS.front();
    }

    bool empty() {
        return curS.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */