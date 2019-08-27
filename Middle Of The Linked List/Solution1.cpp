// 16， 85.46

#include<vector>

using namespace std;

class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0;
        int end = A.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (mid == 0) {
                return 1;
            }

            // mid will never equals to A.size() - 1

            if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) {
                start = mid + 1;
            } else if (A[mid - 1] > A[mid] && A[mid] > A[mid + 1]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};