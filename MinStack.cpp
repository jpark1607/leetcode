/* Problem 155. Min Stack
 * https://leetcode.com/submissions/detail/568800822/
 * 1. 문제:
 *   최저값을 검색할 수 있는 stack(MinStack)을 구현하여라.
 *
 * 2. 아이디어:
 *   stack을 두 개 쓰고, 매 번 push 시 최저값도 검색해서 같이 push하면 된다.
 *   ps. INT_MAX는 push할 때 m이 empty여서 m.top()에서 에러가 나서 넣은 것이다. if/else로 처리도 가능하다.
 *
 *   if (m.empty())
 *     m.push(val);
 *   else
 *     m.push(min(m.top(), val));
 * */
class MinStack {
private:
    stack<int> v;
    stack<int> m;
public:
    MinStack() {
        m.push(INT_MAX);
    }

    void push(int val) {
        v.push(val);
        m.push(min(m.top(), val));
    }

    void pop() {
        v.pop();
        m.pop();
    }

    int top() {
        return v.top();
    }

    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */