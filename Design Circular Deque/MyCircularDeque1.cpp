// 52, 62.96

class MyCircularDeque1 {
private:
	int* a;
	int start;
	int end;
	int size;
	int len;
	int count;

public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		a = new int[k + 1];
		size = k;
		start = 0;
		end = 0;
		count = 0;
		len = k + 1;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (isFull()) {
			return false;
		}

		start = (start == 0) ? size : start - 1;

		a[start] = value;

		count += 1;

		return true;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (isFull()) {
			return false;
		}

		a[end] = value;

		end = (end + 1) % len;

		count += 1;

		return true;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (isEmpty()) {
			return false;
		}

		start = (start + 1) % len;

		count -= 1;

		return true;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (isEmpty()) {
			return false;
		}

		end = (end == 0) ? size : end - 1;

		count -= 1;

		return true;
	}

	/** Get the front item from the deque. */
	int getFront() {
		return isEmpty() ? -1 : a[start];
	}

	/** Get the last item from the deque. */
	int getRear() {
		return isEmpty() ? -1 : ((end == 0) ? a[size] : a[end - 1]);
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return count == 0;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return count == size;
	}
};