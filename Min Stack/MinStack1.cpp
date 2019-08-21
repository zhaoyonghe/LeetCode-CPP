// 36, 94.24

#include<stack>

using namespace std;

class MinStack1 {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        mainStack.push(x);

        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
