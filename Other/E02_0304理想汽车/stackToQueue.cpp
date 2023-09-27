/**
 * @file stackToQueue.cpp
 * @author Histone Von (fengclchn@outlook.com)
 * @brief 两个栈合成一个队列
 * @version 0.1
 * @date 2023-03-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class stackToQueue {
private:
    stack<int> stack_1;
    stack<int> stack_2;
public:
    stackToQueue(/* args */);
    ~stackToQueue();
    void push(int node);
    int pop();
    bool empty();
};

stackToQueue::stackToQueue(/* args */) {}

stackToQueue::~stackToQueue() {}

void stackToQueue::push(int node) {
    stack_1.push(node);
}

int stackToQueue::pop() {
    if (stack_1.empty()) {
        return -1;
    }
    while (!stack_1.empty()) {
        stack_2.push(stack_1.top());
        stack_1.pop();
    }
    int res = stack_2.top();
    stack_2.pop();
    while (!stack_2.empty()) {
        stack_1.push(stack_2.top());
        stack_2.pop();
    }
    return res;
}

bool stackToQueue::empty() {
    return stack_1.empty();
}

int main() {
    int a[] = { 0,1,2,3,4,5 };
    vector<int> test(a, a + 6);
    stackToQueue sq;
    for (int i = 0; i < test.size(); ++i) {
        sq.push(test[i]);
    }
    while (!sq.empty()) {
        cout << sq.pop() << endl;
    }
    return 0;
}
