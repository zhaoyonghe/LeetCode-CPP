// 0, 100.00

#include <stack>

using namespace std;

class MyQueue2 {
private:
    stack<int> st;
    stack<int> aux;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (aux.empty()) {
            aTob(st, aux);
        }
        int num = aux.top();
        aux.pop();
        return num;
    }

    /** Get the front element. */
    int peek() {
        if (aux.empty()) {
            aTob(st, aux);
        }
        return aux.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty() && aux.empty();
    }

    void aTob(stack<int>& a, stack<int>& b) {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }


};