// 40, 93.28

class MyCircularQueue1 {
private:
    int* a;
    int start;
    int end;
    int len;
    int size;
    int count;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        a = new int[k + 1];
        size = k;
        len = size + 1;
        start = 0;
        end = 0;
        count = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        a[end] = value;

        end = (end + 1) % len;
        count += 1;

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        start = (start + 1) % len;
        count -= 1;

        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : a[start];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : ((end == 0) ? a[size] : a[end - 1]);
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == size;
    }
};
