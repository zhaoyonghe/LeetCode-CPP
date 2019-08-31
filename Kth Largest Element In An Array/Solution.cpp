// 12, 92.05

#include<vector>

using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(k + 1, 0);
        for (int i = 0; i < k; i++) {
            heap[i + 1] = nums[i];
        }
        for (int i = k / 2; i > 0; i--) {
            heapify(heap, i);
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > heap[1]) {
                heap[1] = nums[i];
                heapify(heap, 1);
            }
        }
        return heap[1];
    }

    void heapify(vector<int>& heap, int i) {
        int n = heap.size();
        while (true) {
            int index = i;
            if (i * 2 < n && heap[index] > heap[i * 2]) {
                index = i * 2;
            }
            if (i * 2 + 1 < n && heap[index] > heap[i * 2 + 1]) {
                index = i * 2 + 1;
            }
            if (i == index) {
                return;
            }
            int temp = heap[i];
            heap[i] = heap[index];
            heap[index] = temp;
            i = index;
        }
    }
};