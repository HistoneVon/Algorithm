#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;
    queue<int> q2;
    MyStack() {}

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int s = q.size();
        --s;
        while (s--) {
            q2.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        q = q2;
        while (!q2.empty()) {
            q2.pop();
        }
        return res;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
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