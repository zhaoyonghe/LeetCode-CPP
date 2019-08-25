// 4, 77.32

#include <stack>

using namespace std;

class MyQueue1 {
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
        aTob(st, aux);
        int num = aux.top();
        aux.pop();
        aTob(aux, st);
        return num;
    }

    /** Get the front element. */
    int peek() {
        aTob(st, aux);
        int num = aux.top();
        aTob(aux, st);
        return num;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }

    void aTob(stack<int>& a, stack<int>& b) {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }


};
